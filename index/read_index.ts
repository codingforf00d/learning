// Given a path to a directory containing an index file, index.txt, and zero or more other files, 
// read the index file (which contains one filename per line), then read each of the files listed in the index concurrently, 
// concat the resulting strings (in the order specified by the index), and write the result to stdout.

// The program's exit code should be 0 if the entire operation is successful; 1 otherwise.

// All side effects must be isolated to the main function. Impure functions may be defined at the top level but may only be invoked in main.

import * as path from 'path';
import { Readable } from 'stream';


async function* generator(variable) {
    yield 'a';
}

async function main(indexFilePath: string) {

    const readable = Readable.from(generator(__dirname), {encoding: 'utf-8'});
    readable.on('data', (chunk) => console.log(chunk))
   
}

main('aaa').then()