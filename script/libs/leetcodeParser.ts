import * as request from 'request';
import * as fs from 'fs'

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
        request
            .get(uri)
            .on('response', (response : string) => {
                resolve(response);
            });
    });
}

interface leetcode_probelms_meta
{
    [index : number] : string;
}

enum Difficulty {Hard = 3, Medium = 2, Easy = 1}

class leetcode_problem_detail
{
    uri : string;
    name : string;
    difficulty : Difficulty;
    constructor(uri_ : string, name_ : string, difficulty_ : Difficulty)
    {
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
async function parserProblemDetail(meta : string) : Promise<leetcode_problem_detail>
{
    //TODO:
    let detail = new leetcode_problem_detail("A", "B", Difficulty.Easy);
    return detail;
}

async function parserNewProblem(leetcode_htmls : string[], first_new_id : number)
{
    
}

async function main()
{
    let rsp = await fetch("http://www.baidu.com/");
    console.log(rsp);
    let xx = Difficulty[Difficulty.Easy];
    console.log(xx);
}

async function debug_fetchSaveLeetcodeURL()
{
    let html = await fetch(leetcode_uri.algorithms);
    console.log(html);
    fs.writeFileSync("./leetcode_algorithm_html.html", html);
}

async function debug()
{
    debug_fetchSaveLeetcodeURL();
}

export {main, debug};