import * as request from 'request';
import * as fs from 'fs'
import * as path from 'path'
import {execSync as execSync} from 'child_process';
import * as readlineSync from 'readline-sync';

const leetcode_base_uri = 'https://leetcode.com/';
const leetcode_api_uri = {
    algorithms: 'api/problems/algorithms',
    database: 'api/problems/database',
    shell: 'api/problems/shell'
};
const lang_dir_name = {
    'cpp': 'cpp',
    'javascript': 'javascript',
    'haskell': 'haskell'
};
const lang_file_name = {
    'cpp': 'program.cpp',
    'javascript': 'program.js',
    'haskell': 'program.sc'
};
const lang_pre_code_snip = {
    'cpp' : '#include \"../include/pre.h\"\n\n\nint main()\n{\n    return 0;\n}'
}

function get_default_lang_dir_name(lang : string) : string {
    if (lang_dir_name[lang]) return lang_dir_name[lang];
    else return lang;
}

function get_default_lang_file_name(lang : string) : string {
    if (lang_file_name[lang]) return lang_file_name[lang];
    else return 'program.' + lang;
}

function get_default_lang_snip(lang : string) :string {
    if (lang_pre_code_snip[lang]) return lang_pre_code_snip[lang];
    else return '\n';
}

function get_pkg_version() : string {
    let pjson = require('../package.json');
    return pjson.version;
}

class ProblemSolution {
    language : string;
    dir : string;
    solution_uri : string;
    constructor(l : string, d? : string, s? : string) {
        this.language = l;
        this.dir = d || get_default_lang_dir_name(l);
        if (s) this.solution_uri = s;
    }
}

function makeup_file_and_path_for_problem_solution(src_path : string, problem_base_dir : string, solu : ProblemSolution) {
    fs.mkdirSync(path.resolve(src_path, problem_base_dir));
    fs.mkdirSync(path.resolve(src_path, problem_base_dir, get_default_lang_dir_name(solu.language)));
    console.log('file has been created at:', path.resolve(
            src_path, 
            problem_base_dir, 
            get_default_lang_dir_name(solu.language), 
            './' + get_default_lang_file_name(solu.language)
        ));
    fs.writeFileSync(
        path.resolve(
            src_path, 
            problem_base_dir, 
            get_default_lang_dir_name(solu.language), 
            './' + get_default_lang_file_name(solu.language)
        ), 
        get_default_lang_snip(solu.language)
    );
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
function parserProblemDetail(problemNode : any)
{
    //TODO:
    let detail = new ProblemType(
        problemNode['stat']['question__title_slug'], 
        problemNode['stat']['question__title'], 
        problemNode['difficulty']['level']
    );
    return detail;
}

function parserNewProblems(problems :　ProblemsType, leetcode_json_datas : any[], first_new_id : number) : number
{
    let new_last_id : number = 0;
    for (let id in leetcode_json_datas)
    {
        let leetcode_json_data : any[] = leetcode_json_datas[id];
        for (let elem_id in leetcode_json_data)
        {
            let problemNode : any = leetcode_json_data[elem_id];
            let problem_id : number = problemNode['stat']['question_id'];
            new_last_id = new_last_id > problem_id ? new_last_id : problem_id;
            console.log(problem_id);
            if (problem_id >= first_new_id)
                problems[problem_id] = parserProblemDetail(problemNode);
        }
    }
    return new_last_id;
}

class ConfigType {
    last_update : Date;
    last_index : number;
    program_version : string;
    problems : ProblemsType;
    constructor(){
        this.program_version = get_pkg_version();
        this.last_update = new Date;
        this.last_index = 0;
        this.problems = {};
    }
}

class Config {
    src_path : string;
    isValid : boolean;
    obj : ConfigType;
    json_file_path : string;
    readme_template_file_path : string;
    readme_file_path : string;

    constructor(path : string, filename : string) {
        this.src_path = path;
        if (this.check_json_data_vaild(filename)) this.load_from_json_file(filename);
        else {
            this.json_file_path = filename;
            this.isValid = false;
        }
    }

    load_from_json_file(filename : string) {
        this.json_file_path = filename;
        this.obj = (<ConfigType>JSON.parse(fs.readFileSync(filename, 'utf-8')));
        this.isValid = true;
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
        this.obj.last_index = parserNewProblems(this.obj.problems, leetcode_json_datas, this.obj.last_index + 1);
        this.write_back_to_json();
    }

    /**
     * Generate a markdown file by new info within this obj
     * @filename destination file
     * @template_file_name template file
     */
    generate_readme_file(filename : string, template_file_name : string) {
        //TODO:
    }

    async generate_new_solution(id : number, lang : string) {
        if (id > this.obj.last_index) await this.update_from_leetcode();
        if (id > this.obj.last_index) {
            console.log('invalid problem id');
            return;
        }
        let solu = new ProblemSolution(lang);
        console.log('Problem ', id, ':');
        console.log('name:\t\t', this.obj.problems[id].name);
        console.log('base dir:\t', this.obj.problems[id].base_dir);
        console.log('language:\t', solu.language);
        makeup_file_and_path_for_problem_solution(this.src_path, this.obj.problems[id].base_dir, solu);
        this.obj.problems[id].solutions.push(solu);
        this.write_back_to_json();
    }

    commit_solution(id : number, lang : string, solution_uri : string, auto_git : boolean) {
        let solus = this.obj.problems[id].solutions;
        let lang_id : number = -1;
        for (let i in solus) {
            if (solus[i].language === lang) {
                lang_id = parseInt(i);
                break;
            }
        }
        if (lang_id === -1) {
            console.log('No such solution exist, try generate one first');
            return;
        }
        solus[lang_id].solution_uri = solution_uri;
        
        this.generate_readme_file(this.readme_file_path, this.readme_template_file_path);

        if (auto_git) {
            execSync('git status', { stdio: 'inherit' });
            if (readlineSync.keyInYN('Do you want auto-commit?')) {
                execSync('git add .', { stdio: 'inherit' });
                let commit_body = id + ' ' + this.obj.problems[id].name;
                execSync('git commit -m\"' + commit_body + '\"', { stdio: 'inherit' });
                console.log(commit_body);
}
        }
    }

    check_json_data_vaild(filename : string) : boolean{
        let oldobj = JSON.parse(fs.readFileSync(filename, 'utf-8'));
        if (oldobj['program_version'] && oldobj['program_version'] === get_pkg_version()) {
            return true;
        }
        return false;
    }

    /**
     * update from 0.1.0 to 1.0.0
     * @filename legacy json file path
     */
    update_old_json_config(filename : string) {
        let oldobj = JSON.parse(fs.readFileSync(filename, 'utf-8'));
        // do nothing if veision is same
        if (oldobj['program_version'] && oldobj['program_version'] === get_pkg_version()) {
            console.log('Already updated');
            return;
        }
        this.obj = new ConfigType();
        this.obj.last_update = oldobj.last_update;
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