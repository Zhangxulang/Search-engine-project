# 定制化内容搜索引擎

## 项目简介

这是一款在Linux环境下用C++实现的定制化内容搜索引擎，旨在提供高效的搜索体验。

## 运行前期准备

在启动程序之前，请按照以下步骤准备您的数据和环境：

### 1. 准备搜索内容

请将需要搜索的内容生成XML格式文件，示例如下：

```xml
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<rss version="2.0">
    <channel>
        <title><![CDATA[汽车频道]]></title>
        <image>
            <title><![CDATA[汽车频道]]></title>
            <link>http://auto.people.cn</link>
            <url>http://www.people.cn/img/2014peoplelogo/rmw_logo.gif</url>
        </image>
        <description><![CDATA[汽车新闻]]></description>
        <link>http://auto.people.cn</link>
        <language>zh-cn</language>
        <generator>www.people.cn</generator>
        <copyright><![CDATA[Copyright 1997-2016 by www.people.com.cn. all rights reserved]]></copyright>
        <pubDate>2021-05-18 17:26:42</pubDate>

        <item>
            <title><![CDATA[车门锁栓存隐患 福特召回千辆进口林肯MKZ]]></title>
            <link>http://auto.people.com.cn/n1/2021/0208/c1005-32025697.html</link>
            <pubDate>2021-02-08</pubDate>
            <author>人民网</author>
            <description><![CDATA[
                <p style="text-indent: 2em;">近日，福特汽车（中国）有限公司根据《缺陷汽车产品召回管理条例》和《缺陷汽车产品召回管理条例实施办法》要求，向国家市场监督管理总局备案召回计划，决定自2021年3月1日起，召回2014年6月11日-2015年2月12日生产的部分2015年款进口林肯MKZ汽车，共计2290辆。</p>
                <p style="text-indent: 2em;">本次召回范围内的车辆，由于供应商原因，部分车门锁栓的爪簧调整片底座经过长时间使用可能会出现断裂现象，导致车门无法上锁；或上锁的车门可能在车辆行驶时出现解锁的情况，增加乘员受伤风险，存在安全隐患。</p>
                <p style="text-indent: 2em;">福特汽车（中国）有限公司将委托林肯品牌授权经销商，为召回范围内的车辆免费更换经过设计改善的车门锁栓，以消除安全隐患。（刘洋 刘晓梦）</p>
            ]]></description>
        </item>
    </channel>
</rss>
```

### 2. 将XML文件放入指定目录

请将生成的XML文件放入项目目录下的 `data/xml` 文件夹中。

### 3. 编译项目

在以下目录中分别执行 `make` 命令进行编译：

- `项目目录/src/DictProducer`
- `项目目录/src/PagePreprocessor`
- `项目目录/client`
- `项目目录`

### 4. 运行程序

在 `bin` 目录下，首先执行以下命令生成网页库和词典库：

#### 生成网页库

./PageProcessor

#### 生成词典库

./Cutter

### 5. 修改配置文件

请根据实际情况修改 `conf/server.conf` 文件中的相关配置信息，如 `server_ip` 等。

## 程序启动

启动程序的步骤如下：

1. 在 `bin` 目录下运行服务器：

   ```bash
   bash
   复制
   ./SEserver
   ```

2. 在另一个终端窗口中运行客户端：

   ```bash
   bash
   复制
   ./client
   ```

## 项目目录结构

```plaintext
plaintext复制bin/            # 可执行文件
client/         # 客户端代码文件
src/            # 源代码文件
    ├── DictProducer/   # 词典生成模块
    ├── PagePreprocessor/ # 页面预处理模块
    └── ...             # 其他模块
include/        # 服务器端头文件
conf/           # 配置信息文件
lib/            # 第三方库文件
obj```plaintext
obj/            # 编译生成的目标文件
data/
├── xml/        # 存放待搜索内容的XML文件
└── ...         # 其他数据文件
```

## 功能说明

### 1. 页面处理模块 (PagePreprocessor)

- 负责读取XML文件并提取有用信息。
- 对内容进行必要的清洗和格式化。
- 将处理后的数据存储到网页库中以供后续搜索使用。

### 2. 词典生成模块 (DictProducer)

- 从网页库中提取关键词，构建索引。
- 生成词典库，提升搜索效率。

### 3. 搜索引擎模块 (SEserver)

- 提供用户友好的搜索接口。
- 支持关键词搜索与结果排序，返回相关的网页链接及摘要。

### 4. 客户端模块 (client)

- 用户输入关键词，发送请求至服务器。
- 显示搜索结果，包括标题、链接和简要描述。

## 常见问题

### Q1: 如何添加新的数据源？

将新的XML文件放入 `data/xml` 目录，并在运行 `./PageProcessor` 之前确保文件格式正确。

### Q2: 如何修改搜索引擎的配置？

编辑 `conf/server.conf` 文件，根据需要修改IP地址、端口号等配置项。

### Q3: 如果编译失败，我该怎么办？

请检查以下内容：

- 确保所有必要的依赖库已安装。
- 确保Makefile配置正确。
- 查看编译时的错误信息并进行相应的调整。

## 结语

感谢您使用我们的定制化内容搜索引擎项目！如有任何疑问或建议，欢迎与我们联系。
