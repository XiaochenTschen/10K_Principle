### 如何在Ubuntu系统下准备TypeScript的开发环境。

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

### 如何初始化简单的项目

在项目文件夹下运行如下指令。该指令会生成一个默热的tsconfig.json文件。
```bash
tsc --init
```
除了文件中的默认配置选项，下面的一些选项也可以用来简化开发过程。
```json
"rootDir": "./src",      // 项目源文件所在的位置
"outDir": "./dist",      // 编译后javascript所在的位置，如果文件夹不存在会自动创建
"noEmitOnError": true,   // 如果编译出现错误将不会产生任何js文件
```
这样配置以后，可以直接运行`tsc` 指令来完成编译过程。

### 安装第三方依赖

在项目根目录下使用下列执行进行第三方库的安装，第三方库将会被安装到 ./node_module文件夹下。
```bash
npm install package_name
```
使用这种方式安装的第三方库会被记录到package.json文件中，安装内容只是在项目范围内可见，有利于项目之间的环境隔离。
如果其他热想使用或者测试该项目，只要有package.json文件，开发人员只需要运行 `npm install` 指令就可以安装所有的依赖。

如果希望第三方依赖全局可见，那么可以使用指令
```bash
npm install -g package_name
```