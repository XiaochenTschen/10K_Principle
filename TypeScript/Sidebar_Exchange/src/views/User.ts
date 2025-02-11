export class User {
    private username: string;
    private password: string;
  
    constructor(username: string = '', password: string = '') {
      this.username = username;
      this.password = password;
    }
  
    // 更新字段值
    updateUserName(value: string): void {
      this.username = value;
    }
  
    updatePassword(value: string): void {
      this.password = value;
    }
  
    // 获取用户信息
    getUserInfo(): string {
      return `User Name: ${this.username}, Password: ${this.password}`;
    }
}
  