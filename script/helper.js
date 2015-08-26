(function(){
'use strict';
let program = require('commander');
let fs = require('fs');
let path = require('path');
let request = require('sync-request');

const leetcode_base_uri = 'https://leetcode.com/';
const leetcode_uri = {
    'algorithms': 'https://leetcode.com/problemset/algorithms/',
    'database': 'https://leetcode.com/problemset/database/',
    'shell': 'https://leetcode.com/problemset/shell/'
};
const repo_root_path = path.resolve(__dirname, '../');
const list_data_file = path.resolve(repo_root_path, './problems.json');

program.version('0.1.0');
program
    .command('init')
    .description('initialize the repo with /src and problems.json(data and cache)')
    .action(function(){
        newcachefile();
    });
program
    .command('new <problem_num> [dir_name]')
    .description('add new solution to this repository. a dir with specific name will be create')
    .action(function(problem_num, dir_name){
        console.log('Problem Number is : %j', problem_num);
        console.log('Problem dir name is : ', optional_dir_name | '__default__');
    });
program
    .command('solve <problem_num> [solution_code]')
    .description('add solving infomations to specific problems with (or not) solution uri code')
    .action(function(problem_num, solution_code){
        console.log('Problem Number is : %j', problem_num);
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
        update_cache();
    });
program
    .command('*')
    .action(function(){
        console.error('unknown commond');
        program.help();
    });
program.parse(process.argv);

function make_dir_name(str) {
    return str.replace(/ /, '_');
}

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
    let get_difficulty =  function(){
        let reg = /[1-3](?='>)/;
        return str.match(reg)[0];
    };
    let data = {};
    data.uri = get_uri();
    data.name = get_name();
    data.difficulty = get_difficulty();
    return data;
}

function leetcode_html_parser_all(leetcode_htmls, last_index){
    let offset = last_index | 1;
    let num = last_index | 1;
    let rst = [];
    let parser_helper = function(index){
        console.log(num);
        const reg_str = `<td>${ num }</td>(\n.*?)*?</tr>`;
        let reg = new RegExp(reg_str);
        let rst_single = reg.exec(leetcode_htmls[index]);
        if (rst_single !== null){
            let reg = new RegExp('\\d+');
            //console.log(reg.exec(rst_single));
            //console.log(rst_single[0]);
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

function update_cache(){
    if (!fs.existsSync(list_data_file)) {
        newcachefile();
        return true;;
    }
    else {
        let data = JSON.parse(fs.readFileSync(list_data_file, 'utf-8'));
        data.last_update = new Date();
        let offset = data.last_index + 1;
        //test error
        if (data['problems'][data.last_index] === null || typeof data['problems'][offset] !== 'undefined'){
            console.error('Cache file has error, please check and fix it.');
            console.log('last_index:', data.last_index);
            console.log(data['problems'][data.last_index]);
            console.log('next_index:', offset);
            console.log(data['problems'][offset]);
            console.log('detail: last_index does not equal to solutions listed');
            return;
        }
        let problems_meta = leetcode_html_parser_all(get_html_all(), offset);
        for (let x in problems_meta){
            data.problems[parseInt(x) + offset] = parser_detail(problems_meta[x]);
            data.problems[parseInt(x) + offset].is_solved = false;
        }
        data.last_index += problems_meta.length;
        fs.writeFileSync(list_data_file,JSON.stringify(data, null, 4));
    }
}

})();
