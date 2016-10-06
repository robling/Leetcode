import * as program from 'commander'
import {Config as Config} from './configHandler'

function get_pkg_version() : string{
    let pjson = require('../package.json');
    return pjson.version;
}

function CLRParser(cfg : Config, args : any) {
    program.version(get_pkg_version());
    program
        .command('init')
        .description('initialize the repo with /src and problems.json(data and cache)')
        .action(function() {
            //TODO
            console.log('init');
        });
    program
        .command('new <problem_num> [lang]')
        .description('add new solution to this repository. a dir with specific name will be create')
        .action(function(problem_num : number, optional_lang? : string) {
            cfg.generate_new_solution(problem_num, optional_lang || 'cpp');
        });
    program
        .command('solve <problem_num> [lang] [solution_code] [auto_git]')
        .description('add solving infomations to specific problems with (or not) solution uri code')
        .action(function(problem_num : number, lang : string, solution_code? : string, auto_git? : string) {
            console.log('solve');
            cfg.commit_solution(problem_num, lang, solution_code, auto_git === 'autogit');
        });
    program
        .command('update')
        .description('update data file from older version')
        .action(function() {
            cfg.update_old_json_config(cfg.json_file_path);
        });
    program
        .command('debug')
        .description('debug enterpoint, do not use it')
        .action(function() {
            console.log('debug');
            cfg.update_from_leetcode();
        });
    program
        .command('*')
        .action(function(){
            console.error('unknown commond');
            program.help();
        });
    program.parse(args);
}
export {CLRParser};