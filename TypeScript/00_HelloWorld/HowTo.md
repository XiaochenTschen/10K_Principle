如何在Ubuntu系统下准备TypeScript的开发环境。

#### Node.js
```bash
sudo apt update
sudo apt install curl
curl --version
curl -fsSL https://deb.nodesource.com/setup_lts.x | sudo -E bash -
sudo apt-get install -y nodejs
node -v
npm -v
```

#### TypeScript 编译器
```bash
sudo npm install -g typescript
tsc -v
```

#### 编译并执行
```bash
tsc helloworld.ts
node helloworld.js
```