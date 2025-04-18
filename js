<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>JavaScript 完全学习手册</title>
    <style>
        body {font-family: Arial, sans-serif; line-height: 1.6; max-width: 800px; margin: 0 auto; padding: 20px;}
        .code-box {background: #f4f4f4; padding: 15px; border-radius: 5px; margin: 10px 0;}
        .demo-area {border: 1px solid #ddd; padding: 15px; margin: 15px 0;}
        button {padding: 8px 15px; margin: 5px; cursor: pointer;}
    </style>
</head>
<body>
<h1>JavaScript 完全学习手册</h1>

<!-- 变量与常量 -->
<section class="demo-area">
    <h2>1. 变量与常量</h2>
    <div class="code-box">
            <pre><code>// var存在变量提升，let/const有块级作用域
var globalVar = "全局变量";
let blockVar = "块级变量";
const PI = 3.1415; // 常量不可重新赋值</code></pre>
    </div>
</section>

<!-- 数据类型 -->
<section class="demo-area">
    <h2>2. 数据类型</h2>
    <div class="code-box">
            <pre><code>// 原始类型
let str = "字符串";
let num = 123;
let bool = true;
let nul = null;
let undef = undefined;
let sym = Symbol('标识符');

// 引用类型
let obj = { name: "对象" };
let arr = [1, 2, 3];
let func = function() {};</code></pre>
    </div>
    <button onclick="showType()">显示类型</button>
    <p id="typeOutput"></p>
</section>

<!-- 流程控制 -->
<section class="demo-area">
    <h2>3. 流程控制</h2>
    <div class="code-box">
            <pre><code>// 条件语句
let age = 18;
if (age >= 18) {
    console.log("成年人");
} else {
    console.log("未成年人");
}

// switch语句
let day = new Date().getDay();
switch(day) {
    case 0: console.log("周日"); break;
    // ...其他case
    default: console.log("工作日");
}</code></pre>
    </div>
</section>

<!-- 循环结构 -->
<section class="demo-area">
    <h2>4. 循环结构</h2>
    <div class="code-box">
            <pre><code>// for循环
for(let i=0; i<5; i++) {
    console.log(i);
}

// while循环
let j = 0;
while(j < 3) {
    console.log(j++);
}

// 数组遍历
[1,2,3].forEach(item => console.log(item));</code></pre>
    </div>
    <button onclick="runLoops()">运行循环示例</button>
</section>

<!-- 函数系统 -->
<section class="demo-area">
    <h2>5. 函数系统</h2>
    <div class="code-box">
            <pre><code>// 函数声明
function add(a, b) {
    return a + b;
}

// 函数表达式
const multiply = function(a, b) {
    return a * b;
}

// 箭头函数
const square = x => x * x;

// 立即执行函数
(function() {
    console.log("立即执行");
})();</code></pre>
    </div>
</section>

<!-- DOM操作 -->
<section class="demo-area">
    <h2>6. DOM操作</h2>
    <div class="code-box">
            <pre><code>// 元素选择
document.getElementById('demo');
document.querySelector('.class');

// 事件监听
document.querySelector('button').addEventListener('click', () => {
    console.log('按钮被点击');
});

// 动态修改内容
document.getElementById('output').innerHTML = '新内容';</code></pre>
    </div>
    <button onclick="changeColor()">改变背景色</button>
    <div id="colorBox" style="height:50px; background:#eee"></div>
</section>

<!-- 异步编程 -->
<section class="demo-area">
    <h2>7. 异步编程</h2>
    <div class="code-box">
            <pre><code>// Promise示例
new Promise((resolve) => {
    setTimeout(() => resolve('成功'), 1000);
}).then(res => console.log(res));

// async/await
async function fetchData() {
    const res = await fetch('api/data');
    return res.json();
}</code></pre>
    </div>
    <button onclick="showAsync()">运行异步示例</button>
    <p id="asyncOutput"></p>
</section>

<script>
    // 类型检测示例
    function showType() {
        const output = document.getElementById('typeOutput');
        output.innerHTML = `typeof null: ${typeof null}<br>
                                typeof undefined: ${typeof undefined}<br>
                                typeof [1,2]: ${typeof [1,2]}`;
    }

    // 循环示例
    function runLoops() {
        console.log('--- for循环 ---');
        for(let i=0; i<3; i++) console.log(i);

        console.log('--- forEach ---');
        ['a','b','c'].forEach(item => console.log(item));
    }

    // DOM操作示例
    function changeColor() {
        const box = document.getElementById('colorBox');
        box.style.background = `#${Math.floor(Math.random()*16777215).toString(16)}`;
    }

    // 异步示例
    async function showAsync() {
        const output = document.getElementById('asyncOutput');
        output.textContent = '加载中...';
        await new Promise(resolve => setTimeout(resolve, 1000));
        output.textContent = '数据加载完成!';
    }
</script>
</body>
</html>
