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

program.version('1.0.0');
program
    .command('new <problem_num>') //add new solution to this repository
    .action(function(problem_num){
        console.log('Problem Number is : %j', problem_num);
    });
program
    .command('solve <problem_num>') //add solving infomations to
    .action(function(problem_num){
        console.log('Problem Number is : %j', problem_num);
    });
program
    .command('list') //list all solutions that has been submited
    .action(function(){

    });
program
    .command('debug') //list all solutions that has been submited
    .action(function(){
        var data = fs.readFileSync(path.resolve(repo_root_path, './test/test.html'),"utf-8");
        //leetcode_html_parser_all(data);
        newcachefile();
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

function leetcode_html_parser(leetcode_html, num){
    //const reg_str = `<tr>.*<td>.*</td>.*<td>${ num }</td>.*<td>.*</td>.*</tr>`;
    const reg_str = `<td>${ num }</td>(\n.*?)*?</tr>`;
    console.log(reg_str);
    let reg = new RegExp(reg_str, 'g');
    let rst = reg.exec(leetcode_html);
    return rst;
}

function leetcode_html_parser_all(leetcode_htmls){
    let num = 1;
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
            rst[num] = rst_single[0];
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
    let algorithms_html = request('GET', leetcode_uri.algorithms ).body;
    let database_html   = request('GET', leetcode_uri.database   ).body;
    let shell_html      = request('GET', leetcode_uri.shell      ).body;
    return [algorithms_html, database_html, shell_html];
}

function newcachefile() {
    if (fs.existsSync(list_data_file)) { throw("Cache file alerday exist."); }
    let problems_meta = leetcode_html_parser_all(get_html_all());
    var data = {};
    data.last_update = new Date();
    data.last_index = problems_meta.length;
    data.problems = {};
    for (let x in problems_meta){
        data.problems[x] = parser_detail(problems_meta[x]);
    }
    fs.writeFileSync(list_data_file,JSON.stringify(data, null, 4));
}
})();
