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

const dirname : string = __dirname;
console.log(dirname);

import {debug as test} from './libs/leetcodeParser'

test();
