第一次写，还在学习md怎么写比较好，望见谅

用户
Account : user
Password: 123456

管理员
Account : admin
Password: 12345

分为 用户 和 管理员
    用户：
        1.借书
        2.还书
        3.购买
        4.搜索

    管理员：
        1.增加图书数量
        2.增加种类
        3.搜索图书
        4.查看所有图书
        5.修改图书信息

BookList文件读取顺序：
    0 书籍无类
    1 自然科学类
    2 人文社会类
    3 外语类
    信息顺序：BookClass BookName BookCode Price Author Press Count
    读取结束判断利用EOF判断

BorrowedBook文件读取顺序：
    全部为string类元素，仅为书名，录入后对书架进行比对，回复书架上书的数量