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
import * as path from 'path'
import * as fs from 'fs'
const repo_root_path = path.resolve(__dirname, '../');
const source_dir = path.resolve(repo_root_path, 'src');

import {CLRParser as clr} from './libs/clr'
import {Config as Config} from './libs/configHandler'

let cfg = new Config(source_dir, '../ppp.json');
clr(cfg, process.argv);