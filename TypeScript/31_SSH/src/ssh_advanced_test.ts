import { Client } from "ssh2";
import * as fs from 'fs';

// 文件传输测试
const connSftp = new Client();
connSftp.on("ready", () => {
    console.log("Testing SFTP...");
    
    connSftp.sftp((err, sftp) => {
        if (err) throw err;
        
        // 上传文件
        const writeStream = sftp.createWriteStream('/tmp/test.txt');
        writeStream.write('Hello SSH!');
        writeStream.end();
        
        // 下载文件
        const readStream = sftp.createReadStream('/tmp/test.txt');
        readStream.on('data', (data: Buffer) => {
            console.log('Received:', data.toString());
        });
    });
}).connect({
    host: "localhost",
    username: "your_username",
    password: "your_password"
});

// 执行多个命令
const connMulti = new Client();
connMulti.on("ready", () => {
    console.log("Testing multiple commands...");
    
    const commands = [
        "pwd",
        "date",
        "whoami",
        "ls -la"
    ];
    
    const executeCommand = (cmd: string) => {
        connMulti.exec(cmd, (err, stream) => {
            if (err) throw err;
            console.log(`\nExecuting: ${cmd}`);
            stream.on('data', (data: Buffer) => {
                console.log(data.toString());
            });
        });
    };
    
    commands.forEach(executeCommand);
}).connect({
    host: "localhost",
    username: "your_username",
    password: "your_password"
}); 