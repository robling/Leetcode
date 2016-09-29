/// <reference path="typings/index.d.ts" />
/*
 Aim: 
    0. refactor with typescript
    1. split helper functions to subfolder
    2. using await to replace *-sync module
    3. support other languages
    4. ahead version to 2.0
 */
//import {main as test} from './libs/leetcodeParser'
import * as fs from 'fs'
const dirname : string = __dirname;
console.log(dirname);

import {debug as test} from './libs/leetcodeParser'
import {Config as Config} from './libs/configHandler'

let c = new Config();
//c.update_old_json_config('../problems.json');
c.load_from_json_file('../ppp.json');
c.update_from_leetcode();
c.json_file_path = '../ppp2.json';
c.write_back_to_json();

//test();
