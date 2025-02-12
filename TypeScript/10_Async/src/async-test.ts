async function fetchData(): Promise<string> {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
        // 这里可以模拟正常返回数据或者出错，比如：
        // resolve("Fetched Data");
        // 或者模拟错误：reject(new Error("Fetch error"));
        resolve("Fetched Data");
        }, 1000);
    });
}
  
async function processData(): Promise<void> {
    try {
      console.log("开始获取数据...");
      // await 关键字等待 fetchData 返回的 Promise 完成
      const data = await fetchData();
      console.log("数据获取成功:", data);
    } catch (error) {
      // 如果 fetchData 中发生错误，错误会被捕获到这里
      console.error("处理数据时出错:", error);
    }
}
  
processData();
  