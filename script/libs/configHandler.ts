import * as request from 'request';
import * as fs from 'fs'

const leetcode_base_uri = 'https://leetcode.com/';
const leetcode_api_uri = {
    algorithms: 'api/problems/algorithms',
    database: 'api/problems/database',
    shell: 'api/problems/shell'
};

class ProblemSolution {
    language : string;
    dir : string;
    solution_uri : string;
    constructor(l : string, d : string, s : string) {
        this.language = l;
        this.dir = d;
        this.solution_uri = s;
    }
}

class ProblemType{
    uri : string;
    name : string;
    difficulty : number;
    base_dir : string;
    solutions : Array<ProblemSolution>;
    constructor(u : string, n : string, d : number) {
        this.uri = u;
        this.name = n;
        this.difficulty = d;
        this.base_dir = n.replace(/\s+/g, '');
        this.solutions = new Array<ProblemSolution>();
    }
}

interface ProblemsType {
    [index : number] : ProblemType;
}

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

/**
 * Parser leetcode problem string to detailed problem info
 */
async function parserProblemDetail(problemNode : any) : Promise<ProblemType>
{
    //TODO:
    let detail = new ProblemType(
        problemNode['stat']['question__title_slug'], 
        problemNode['stat']['question__title'], 
        problemNode['difficulty']['level']
    );
    return detail;
}

async function parserNewProblems(problems :　ProblemsType, leetcode_json_datas : any[], first_new_id : number)
{
    for (let id in leetcode_json_datas)
    {
        let leetcode_json_data : any[] = leetcode_json_datas[id];
        for (let elem_id in leetcode_json_data)
        {
            let problemNode : any = leetcode_json_data[elem_id];
            let problem_id : number = problemNode['stat']['question_id'];
            console.log(problem_id);
            if (problem_id >= first_new_id)
                problems[problem_id] = await parserProblemDetail(problemNode);
        }
    }
}

class ConfigType {
    last_update : Date;
    last_index : number;
    problems : ProblemsType;
    constructor(lu : Date){
        this.last_update = lu;
        this.problems = {};
    }
}

class Config{
    obj : ConfigType;
    json_file_path : string;
    load_from_json_file(filename : string) {
        this.json_file_path = filename;
        this.obj = (<ConfigType>JSON.parse(fs.readFileSync(filename, 'utf-8')));
    }
    write_back_to_json() {
        fs.writeFileSync(this.json_file_path, JSON.stringify(this.obj, null, 4));
    }
    /**
     * update info from leetcode json datas
     */
    async update_from_leetcode() {
        let leetcode_json_datas = [];
        for (let id in leetcode_api_uri)
        {
            leetcode_json_datas[id]= JSON.parse(await fetch(leetcode_base_uri + leetcode_api_uri[id]))['stat_status_pairs'];
        }
        parserNewProblems(this.obj.problems, leetcode_json_datas, this.obj.last_index + 1);
    }
    /**
     * Generate a markdown file by new info within this obj
     * @filename destination file
     * @template_file_name template file
     */
    generate_readme_file(filename : string, template_file_name : string) {

    }
    //update for 1.0 to 2.0
    update_old_json_config(filename : string) {
        let oldobj = JSON.parse(fs.readFileSync(filename, 'utf-8'));
        this.obj = new ConfigType(oldobj.last_update);
        this.obj.last_index = oldobj.last_index;
        for (let i in oldobj.problems) {
            let re = oldobj.problems[i];
            this.obj.problems[i] = new ProblemType(re.uri, re.name, re.difficulty);
            if (re.is_solved)
                this.obj.problems[i].solutions.push(new ProblemSolution('cpp', 'cpp', re.solution_uri));
        }
        fs.writeFileSync(filename, JSON.stringify(this.obj, null, 4));
    }
}

export {Config}