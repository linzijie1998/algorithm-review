# [两数之和](https://leetcode.cn/problems/two-sum/description/)

## I. 思路
维护一个哈希表, 遍历`nums`数组, 计算索引值`idx = target - nums[i]`, 按照索引找到对应数据则直接返回, 否则把`nums[i]`放入索引。

## II. 解题方法
1. 创建一个空的哈希表
2. 从`0`开始遍历`nums`数组, 计算`target`和`nums[i]`的差值`ans`
   - 如果哈希表中不存在`ans`索引, 则在哈希表中添加`key`: `nums[i]`以及`value`: `i`
   - 如果哈希表中存在`ans`索引, 则返回遍历数组的索引`i`和哈希表中索引`ans`存放的value值

## III. 总结
1. 哈希表的创建方式
    - cpp可使用`unorderd_map`创建一个哈希表: `unordered_map<int, int>`
    - golang使用`make`函数创建一个哈希表: `make(map[int]int)`
2. golang中判断map中是否存在该索引
   ```go
   if _, ok := m[ans]; ok {
        // 存在
    } else {
        // 不存在
    }
   ```