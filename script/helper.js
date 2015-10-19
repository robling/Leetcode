(function(){
'use strict';
let program = require('commander');
let fs = require('fs');
let path = require('path');
let request = require('sync-request');
let swig = require('swig');

const repo_root_path = path.resolve(__dirname, '../');
const list_data_file = path.resolve(repo_root_path, './problems.json');
const list_file = path.resolve(repo_root_path, './README.md');
const source_dir = path.resolve(repo_root_path, 'src');
const fixed_file_name = 'program.cpp';
const pre_code_snip = '#include \"../include/pre.h\"\n\n\nint main()\n{\n    return 0;\n}';
var make_dir_name = function(str) {
    // Problem's name looks like this:
    //      Add Two Numbers
    // Here I simply remove all space
    return str.replace(/\s+/g, '');
};
var make_solution_file = function(dir) {
    fs.mkdirSync(path.resolve(source_dir, dir));
    fs.writeFileSync(path.resolve(source_dir, dir, './'+ fixed_file_name), pre_code_snip);
};
const leetcode_base_uri = 'https://leetcode.com/';
const leetcode_uri = {
    'algorithms': 'https://leetcode.com/problemset/algorithms/',
    'database': 'https://leetcode.com/problemset/database/',
    'shell': 'https://leetcode.com/problemset/shell/'
};

program.version('0.1.0');
program
    .command('init')
    .description('initialize the repo with /src and problems.json(data and cache)')
    .action(function(){
        if (!fs.existsSync(source_dir)) {
            fs.mkdirSync(source_dir);
        }
        newcachefile();
    });
program
    .command('new <problem_num> [dir_name]')
    .description('add new solution to this repository. a dir with specific name will be create')
    .action(function(problem_num, optional_dir_name){
        if (problem_num <= 0) {
            console.error('problem_num should be positive');
            process.exit(1);
        }
        console.log('Problem Number is : %j', problem_num);
        let data = load_data();
        if (problem_num > data.last_index) {
            update_cache();
            data = load_data();
            if (problem_num > data.last_index) {
                console.error(problem_num, ' not yet posted on leetcode');
                process.exit(1);
            }
        }
        if (data.problems[problem_num].is_solved || data.problems[problem_num].dir) {
            console.error('solution allready exists');
            process.exit(1);
        }
        let dir_name;
        if (optional_dir_name) dir_name = optional_dir_name;
        else dir_name = make_dir_name(data.problems[problem_num].name);
        console.log('Problem dir name is : ', dir_name);
        make_solution_file(dir_name);
        data.problems[problem_num].dir = dir_name;
        data_write_back(data);
    });
program
    .command('solve <problem_num> [solution_code]')
    .description('add solving infomations to specific problems with (or not) solution uri code')
    .action(function(problem_num, solution_code){
        console.log('Problem Number is : %j', problem_num);
        let data = load_data();
        data.problems[problem_num].is_solved = true;
        if (solution_code) {
            data.problems[problem_num].solution_uri = solution_code;
        }
        data_write_back(data);
        make_readme_file();
    });
program
    .command('list')
    .description('list all solutions that has been solved')
    .action(function(){

    });
program
    .command('debug')
    .description('debug enterpoint, do not use it')
    .action(function(){
        //update_cache();
        make_readme_file();
        //console.log('Do nothing');
    });
program
    .command('*')
    .action(function(){
        console.error('unknown commond');
        program.help();
    });
program.parse(process.argv);

function parser_detail(str) {
    let get_uri = function(){
        let reg = /".*(?=">)/;
        let rst = str.match(reg)[0];
        return rst.replace(/^"/, '');
    };
    let get_name = function(){
        let reg = />.*(?=<\/a>)/;
        let rst = str.match(reg)[0];
        return rst.replace(/^>/, '');
    };
    let diffStr = {"Hard" : 3, "Medium" : 2, "Easy" : 1};
    let get_difficulty =  function(){
        let reg = /Hard|Medium|Easy(?=<\/td)/;
        let s = str.match(reg)[0];
        return diffStr[s];
    };
    let data = {};
    data.uri = get_uri();
    data.name = get_name();
    data.difficulty = get_difficulty();
    return data;
}

function leetcode_html_parser_all(leetcode_htmls, last_index) {
    let offset = 1;
    if (last_index !== undefined) {
        offset = last_index;
    }
    let num = offset;
    let rst = [];
    let parser_helper = function(index) {
        const reg_str = `<td>${ num }</td>(\n.*?)*?</tr>`;
        let reg = new RegExp(reg_str);
        let rst_single = reg.exec(leetcode_htmls[index]);
        if (rst_single !== null){
            let reg = new RegExp('\\d+');
            rst[num - offset] = rst_single[0];
            num++;
            return true;
        }
        else {
            return false;
        }
    };
    while(true) {
        if (parser_helper(0)){
            continue;
        }
        else if (parser_helper(1)) {
            continue;
        }
        else if (parser_helper(2)) {
            continue;
        }
        else {
            break;
        }
    }
    console.log('All ',num - 1, 'problems loaded');
    return rst;
}

function get_html_all() {
    console.log('Getting leetcode problems page...');
    try {
        let algorithms_html = request('GET', leetcode_uri.algorithms ).body;
        let database_html   = request('GET', leetcode_uri.database   ).body;
        let shell_html      = request('GET', leetcode_uri.shell      ).body;
        return [algorithms_html, database_html, shell_html];
    } catch (e) {
        console.error('Getting leetcode problems page Failed');
        console.error(e);
        process.exit(1);
    }
}

function newcachefile() {
    if (fs.existsSync(list_data_file)) { throw("Cache file alerday exist."); }
    let problems_meta = leetcode_html_parser_all(get_html_all());
    var data = {};
    data.last_update = new Date();
    data.last_index = problems_meta.length;
    data.problems = {};
    for (let x in problems_meta){
        data.problems[parseInt(x) + 1] = parser_detail(problems_meta[x]);
        data.problems[parseInt(x) + 1].is_solved = false;
    }
    fs.writeFileSync(list_data_file,JSON.stringify(data, null, 4));
}

function load_data() {
    return JSON.parse(fs.readFileSync(list_data_file, 'utf-8'));
}

function data_write_back(data) {
    fs.writeFileSync(list_data_file,JSON.stringify(data, null, 4));
}

function update_cache() {
    if (!fs.existsSync(list_data_file)) {
        newcachefile();
        return true;
    }
    else {
        let data = JSON.parse(fs.readFileSync(list_data_file, 'utf-8'));
        data.last_update = new Date();
        let last_index_new = data.last_index + 1;
        //test error
        if (data.problems[data.last_index] === null || typeof data.problems[last_index_new] !== 'undefined'){
            console.error('Cache file has error, please check and fix it.');
            console.log('last_index:', data.last_index);
            console.log(data.problems[data.last_index]);
            console.log('next_index:', last_index_new);
            console.log(data.problems[last_index_new]);
            console.log('detail: last_index does not equal to solutions listed');
            return;
        }
        let problems_meta = leetcode_html_parser_all(get_html_all(), last_index_new);
        for (let x in problems_meta){
            console.log(x);
            data.problems[parseInt(x) + last_index_new] = parser_detail(problems_meta[x]);
            data.problems[parseInt(x) + last_index_new].is_solved = false;
        }
        data.last_index += problems_meta.length;
        fs.writeFileSync(list_data_file,JSON.stringify(data, null, 4));
    }
}
function make_readme_file(){
    if (!fs.existsSync(list_data_file)) {
        newcachefile();
    }
    let data = load_data();
    let to_render = [];
    for (let x in data.problems) {
        if (data.problems[x].is_solved) {
            to_render.push(x);
        }
    }
    var source = {};
    source.leetcode_uri = leetcode_base_uri;
    source.data = data;
    source.solved = to_render;
    source.difficulty = {
        '1': 'Easy',
        '2': 'Medium',
        '3': 'Hard'
    };
    let rst = swig.renderFile(path.resolve(__dirname, './read_me_tpl.md'), source);
    fs.writeFileSync(list_file, rst, 'utf-8');
}

})();
