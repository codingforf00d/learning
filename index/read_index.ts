// Given a path to a directory containing an index file, index.txt, and zero or more other files, 
// read the index file (which contains one filename per line), then read each of the files listed in the index concurrently, 
// concat the resulting strings (in the order specified by the index), and write the result to stdout.

// The program's exit code should be 0 if the entire operation is successful; 1 otherwise.

// All side effects must be isolated to the main function. Impure functions may be defined at the top level but may only be invoked in main.



import { readFile } from 'fs';
import { promisify } from 'util';
const path = require('path');

const readFileAsync = promisify(readFile)

async function reduce(indexFilePath: string, readFileFunc: (path: string, encoding: string) => Promise<string>) {
    const fileArray = await readFileFunc(path.join(indexFilePath, 'index.txt'), 'utf-8').then((value) => value.split('\n'));
    const promise = fileArray.map(
        async (value) => readFileFunc(path.join(indexFilePath, value), 'utf-8'))
    return await Promise.all(promise)
}

reduce(process.cwd(), readFileAsync).then((value) => console.log(value.join('')))