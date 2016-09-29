import * as request from 'request';
import * as fs from 'fs'
import * as config from './configHandler'

const leetcode_base_uri = 'https://leetcode.com/';
const leetcode_uri = {
    algorithms: 'https://leetcode.com/problemset/algorithms/',
    database: 'https://leetcode.com/problemset/database/',
    shell: 'https://leetcode.com/problemset/shell/'
};

/**
 * Async function to fetch url
 */
async function fetch(uri : string) : Promise<string>
{
    return new Promise<string>(resolve => {
        request(uri, (err, res, body)=>{
            resolve(body);
        });
    });
}

enum Difficulty {Hard = 3, Medium = 2, Easy = 1}

class leetcode_problem_detail
{
    id : number;
    uri : string;
    name : string;
    difficulty : number;
    constructor(id_ : number, uri_ : string, name_ : string, difficulty_ : number)
    {
        this.id = id_;
        this.uri = uri_;
        this.name = name_;
        this.difficulty = difficulty_;
    }
}

interface leetcode_problems_detail
{
    [index : number] : leetcode_problem_detail
}

/**
 * Parser leetcode problem string to detailed problem info
 */
async function parserProblemDetail(problemNode : any) : Promise<leetcode_problem_detail>
{
    //TODO:
    let detail = new leetcode_problem_detail(problemNode['stat']['question_id'], 
        problemNode['stat']['question__title_slug'], 
        problemNode['stat']['question__title'], 
        problemNode['difficulty']['level']
    );
    return detail;
}

async function parserNewProblems(leetcode_json_datas : any[], first_new_id : number)
{
    let rst : leetcode_problems_detail = {};
    for (let id in leetcode_json_datas)
    {
        let leetcode_json_data : any[] = leetcode_json_datas[id];
        console.log(leetcode_json_datas);
        for (let elem_id in leetcode_json_data)
        {
            let problemNode : any = leetcode_json_data[elem_id];
            let problem_id : number = problemNode['stat']['question_id'];            
            if (problem_id >= first_new_id)
                rst[problem_id] = await parserProblemDetail(problemNode);
        }
    }
    return rst;
}

async function main()
{
    let rsp = await fetch("http://www.baidu.com/");
    console.log(rsp);
    let xx = Difficulty[Difficulty.Easy];
    console.log(xx);
}

async function debug_fetchSaveLeetcodeDatas()
{
    let jsonData = await fetch(leetcode_uri.algorithms);
    fs.writeFileSync("./leetcode.json", jsonData);
}

async function debug()
{
    let leetcode_json_datas = JSON.parse(fs.readFileSync("./leetcode.json", 'utf-8'));
    let rst = await parserNewProblems([leetcode_json_datas['stat_status_pairs']], 1);
    console.log(rst);
}

export {main, debug};