import { Client } from "ssh2";

// 基本SSH连接测试
const conn = new Client();
conn.on("ready", () => {
    console.log("SSH Connection established!");
    
    // 执行一个简单的命令
    conn.exec("pwd && ls -la", (err, stream) => {
        if (err) throw err;
        stream.on('data', (data: Buffer) => {
            console.log('Output:', data.toString());
        }).on('close', () => {
            conn.end();
        });
    });
}).connect({
    host: "localhost",          // 连接本地主机
    username: "chen",  // 你的Ubuntu用户名
    // 选择以下任一认证方式：
    password: "19920429Xc@",  // 方式1：密码认证
    // privateKey: require('fs').readFileSync('/home/your_username/.ssh/id_rsa') // 方式2：密钥认证
    port: 22
});

// 端口转发测试
const connForward = new Client();
connForward.on("ready", () => {
    console.log("Starting port forwarding...");
    
    // 将本地8080端口转发到本地80端口
    connForward.forwardIn('127.0.0.1', 8080, (err, port) => {
        if (err) {
            console.error("Port forwarding failed:", err);
            return;
        }
        console.log(`Port forwarding established! Listening on port ${port}`);
        console.log("Try accessing http://localhost:8080 in your browser");
    });

    // 处理转发连接
    connForward.on('tcp connection', (info, accept, reject) => {
        console.log('New connection:', info);
        
        const stream = accept();
        // 连接到目标服务器（80端口）
        const net = require('net');
        const socket = new net.Socket();
        socket.connect(80, '127.0.0.1');
        
        // 双向转发数据
        stream.pipe(socket);
        socket.pipe(stream);
    });
}).connect({
    host: "localhost",
    username: "chen",
    password: "19920429Xc@",
    port: 22
});

// 处理程序退出
process.on('SIGINT', () => {
    console.log('\nClosing SSH connections...');
    conn.end();
    connForward.end();
    process.exit();
});
