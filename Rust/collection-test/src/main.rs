use std::collections::HashMap;

fn main() {
    // 假设有一个非常大的字符串，这里仅以一小段示例字符串演示
    let text = "Rust is a systems programming language, focused on safety and performance.
                Rust provides memory safety without using garbage collection.";

    // 使用 split_whitespace 根据空白字符（空格、换行符、制表符等）分割字符串
    // 得到的是 Vec<&str>，每个字符串切片仍指向原始 text 的数据
    let words = text.split_whitespace();

    // 创建一个 HashMap 来存储每个单词及其出现次数
    let mut freq_map: HashMap<String, usize> = HashMap::new();

    // 对每个单词进行遍历，并在过程中去除 “, . \n” 等特殊字符
    for word in words {
        // 使用 chars() 迭代每个字符，然后过滤掉逗号、句号以及换行符
        let cleaned: String = word
            .chars()
            .filter(|c| !",[.\n]".contains(*c))
            .collect();
        
        // 如果清洗后字符串不为空，则更新哈希映射
        if !cleaned.is_empty() {
            // 通过 entry_or_insert 方式统计数量
            *freq_map.entry(cleaned).or_insert(0) += 1;
        }
    }

    // 将 HashMap 转换为 Vec，以便基于频率进行排序
    let mut freq_vec: Vec<(String, usize)> = freq_map.into_iter().collect();
    // 按照频率从高到低排序
    freq_vec.sort_by(|a, b| b.1.cmp(&a.1));

    // 输出排序后的单词及其对应的出现次数
    for (word, count) in freq_vec {
        println!("{}: {}", word, count);
    }
}
