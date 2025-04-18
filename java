/**
 * Java知识大全 - 千行代码入门Java
 * 涵盖基础语法、面向对象、集合框架、IO、异常等核心知识点
 */

// --------------------- 基础数据类型与运算 ---------------------
public class BasicTypes {
    // 八大基本数据类型
    byte b = 10;        // 8位整数, -128~127
    short s = 100;      // 16位整数
    int i = 1_000_000;  // 32位整数, 下划线增强可读性
    long l = 1000L;     // 64位整数, 后缀L
    float f = 3.14F;    // 32位浮点数, 后缀F
    double d = 3.1415;  // 64位浮点数
    char c = 'A';       // 16位Unicode字符
    boolean bool = true;// 布尔值
    
    // 包装类
    Integer intObj = Integer.valueOf(10); // 装箱
    int primitiveInt = intObj;           // 拆箱
    
    // 字符串
    String str = "Hello Java";
    String multiLine = "第一行\n第二行"; // 转义字符
    
    // 运算符
    int sum = 10 + 20;         // 算术运算符
    boolean isEqual = (10 == 20); // 关系运算符
    boolean logicalAnd = true && false; // 逻辑与
    int bitwiseAnd = 5 & 3;    // 位与: 101 & 011 = 001=1
    int shift = 5 << 2;        // 左移: 101 << 2 = 10100=20
    
    // 类型转换
    int a = (int)3.9; // 强制类型转换, 结果3
    double bDouble = a; // 自动类型转换
}

// --------------------- 流程控制 ---------------------
public class ControlFlow {
    // if-else
    public void ifElse(int score) {
        if (score >= 90) {
            System.out.println("A");
        } else if (score >= 80) {
            System.out.println("B");
        } else {
            System.out.println("C");
        }
    }

    // switch (JDK7支持字符串)
    public void switchDemo(String day) {
        switch (day) {
            case "MON":
                System.out.println("星期一");
                break;
            case "TUE":
                System.out.println("星期二");
                break;
            default:
                System.out.println("未知");
        }
    }

    // for循环
    public void forLoop() {
        // 普通for
        for (int i = 0; i < 10; i++) {
            System.out.print(i + " ");
        }
        
        // 增强for(foreach)
        int[] array = {1,2,3,4,5};
        for (int num : array) {
            System.out.print(num + " ");
        }
    }

    // while循环
    public void whileLoop() {
        int count = 0;
        while (count < 5) {
            System.out.print(count + " ");
            count++;
        }
    }

    // do-while
    public void doWhileLoop() {
        int count = 10;
        do {
            System.out.print(count + " ");
            count++;
        } while (count < 5); // 至少执行一次
    }
}

// --------------------- 面向对象基础 ---------------------
// 类与对象
class Person {
    // 成员变量(属性)
    private String name;
    private int age;

    // 构造方法
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // 成员方法
    public void sayHello() {
        System.out.println("Hello, my name is " + name);
    }

    // 方法重载
    public void sayHello(String language) {
        if ("cn".equals(language)) {
            System.out.println("你好, 我叫" + name);
        }
    }

    // Getter/Setter
    public String getName() { return name; }
    public void setName(String name) { this.name = name; }
}

// 继承与多态
class Student extends Person {
    private String school;

    public Student(String name, int age, String school) {
        super(name, age); // 调用父类构造方法
        this.school = school;
    }

    // 方法重写
    @Override // 注解: 标识重写父类方法
    public void sayHello() {
        super.sayHello(); // 调用父类方法
        System.out.println("我在" + school + "上学");
    }
}

// 接口
interface Runner {
    void run(); // 抽象方法
    default void warmUp() { // 默认方法(JDK8+)
        System.out.println("热身运动");
    }
}

// 实现接口
class Athlete extends Student implements Runner {
    public Athlete(String name, int age, String school) {
        super(name, age, school);
    }

    @Override
    public void run() {
        System.out.println("快速奔跑");
    }
}

// --------------------- 异常处理 ---------------------
public class ExceptionDemo {
    // 检查型异常(必须处理)
    public void fileRead() {
        try {
            // FileReader fr = new FileReader("file.txt");
            // 模拟异常
            throw new Exception("文件不存在");
        } catch (Exception e) {
            e.printStackTrace(); // 打印堆栈跟踪
        } finally {
            System.out.println("无论是否异常都会执行");
        }
    }

    // 非检查型异常(运行时异常)
    public void arrayAccess() {
        int[] arr = new int[5];
        try {
            System.out.println(arr[10]); // 数组越界异常
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("错误: " + e.getMessage());
        }
    }

    // 自定义异常
    static class AgeException extends Exception {
        public AgeException(String message) {
            super(message);
        }
    }

    public void checkAge(int age) throws AgeException { // 声明抛出异常
        if (age < 0) {
            throw new AgeException("年龄不能为负数");
        }
    }
}

// --------------------- 集合框架 ---------------------
import java.util.*;

public class CollectionsDemo {
    // List(有序可重复)
    public void listDemo() {
        List<String> list = new ArrayList<>(); // 泛型
        list.add("Apple");
        list.add("Banana");
        System.out.println("大小: " + list.size()); // 2
        System.out.println("是否包含: " + list.contains("Apple")); // true
        
        // 迭代器
        Iterator<String> it = list.iterator();
        while (it.hasNext()) {
            System.out.print(it.next() + " ");
        }
    }

    // Set(无序不可重复)
    public void setDemo() {
        Set<Integer> set = new HashSet<>();
        set.add(10);
        set.add(20);
        set.add(10); // 重复元素不会存储
        System.out.println("Set元素: " + set); // [10, 20]
    }

    // Map(键值对)
    public void mapDemo() {
        Map<String, Integer> map = new HashMap<>();
        map.put("A", 100);
        map.put("B", 200);
        System.out.println("获取值: " + map.get("A")); // 100
        
        // 遍历键值对
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            System.out.println(entry.getKey() + " -> " + entry.getValue());
        }
    }

    // 队列
    public void queueDemo() {
        Queue<String> queue = new LinkedList<>();
        queue.offer("First"); // 入队
        queue.offer("Second");
        System.out.println("出队: " + queue.poll()); // First
    }
}

// --------------------- 输入输出 ---------------------
import java.io.*;

public class IOStream {
    // 字节流(文件读写)
    public void fileCopy(String src, String dest) {
        try (FileInputStream fis = new FileInputStream(src);
             FileOutputStream fos = new FileOutputStream(dest)) {
            byte[] buffer = new byte[1024];
            int len;
            while ((len = fis.read(buffer)) > 0) {
                fos.write(buffer, 0, len);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // 字符流(文本处理)
    public void readTextFile(String path) {
        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // 对象序列化
    public void serializeObject(Object obj, String path) {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(path))) {
            oos.writeObject(obj);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public Object deserializeObject(String path) {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(path))) {
            return ois.readObject();
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }
}

// --------------------- 高级特性 ---------------------
// 泛型
class GenericClass<T> {
    private T value;

    public GenericClass(T value) {
        this.value = value;
    }

    public T getValue() {
        return value;
    }
}

// 枚举
enum Season {
    SPRING, SUMMER, AUTUMN, WINTER;

    public String getDescription() {
        switch (this) {
            case SPRING: return "春暖花开";
            default: return "未知季节";
        }
    }
}

// 注解
@SuppressWarnings("unused") // 抑制警告
public class AnnotationsDemo {
    @Override
    public String toString() {
        return "自定义toString";
    }
}

// --------------------- 综合示例 ---------------------
public class JavaMastery {
    public static void main(String[] args) {
        // 数据类型演示
        BasicTypes basic = new BasicTypes();
        System.out.println("字符串长度: " + basic.str.length());
        
        // 流程控制
        ControlFlow control = new ControlFlow();
        control.forLoop();
        
        // 面向对象
        Student student = new Student("张三", 18, "清华");
        student.sayHello();
        
        // 异常处理
        ExceptionDemo exception = new ExceptionDemo();
        exception.fileRead();
        
        // 集合
        CollectionsDemo collections = new CollectionsDemo();
        collections.mapDemo();
        
        // IO操作
        IOStream io = new IOStream();
        io.readTextFile("test.txt");
        
        // 泛型
       GenericClass<String> gen = newGenericClass<>("泛型示例");
        System.out.println(gen.getValue());
        
        // 枚举
        System.out.println(Season.SPRING.getDescription());
    }
}

// --------------------- 知识点说明 ---------------------
/*
1. 基本数据类型: 8种原始类型+包装类, 注意自动拆装箱
2. 流程控制: 支持所有主流控制结构, switch支持字符串(JDK7+)
3. 面向对象: 封装(访问修饰符private/protected/public)、继承(单继承)、多态(重写+接口)
4. 异常体系: Throwable分为Error(不可恢复)和Exception(检查型/非检查型)
5. 集合框架: List/Set/Map三大体系, 常用实现类ArrayList/HashSet/HashMap
6. IO流: 字节流(处理二进制)vs字符流(处理文本), 推荐使用try-with-resources自动关闭
7. 泛型: 类型安全, 减少强制类型转换, 支持类型上限<T extends Number>
8. 枚举: 单例模式最佳实践, 可定义构造方法和成员方法
9. 注解: 元数据, 常用@SuppressWarnings/@Override/@Deprecated
10. 其他: 多线程(Runnable/Thread)、反射(Class类)、Lambda表达式(JDK8+)等
*/
