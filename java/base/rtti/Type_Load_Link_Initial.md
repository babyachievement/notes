#类型的生命周期

为了使类类型可用，虚拟机将对类型进行加载，链接和初始化。

1. 加载（Loading）：由类加载器执行，该步骤将查找字节码，将字节码加载到JVM中，并从这些字节码创建一个Class对象。
2. 链接（Linking）：链接是将二进制类型数据合并为虚拟机的运行时状态，这个过程又分成3步：验证，准备和解析。验证确保类型正确、可引用。实现可能会将解析步骤延迟到每个类型引用被实际使用时。
3. 初始化（Initialization）：如果该类有超类，对其初始化，执行静态初始化器和静态初始化块。

初始化被延迟到了对静态方法（构造器隐式地是静态的）或者非常数静态域进行首次引用时才进行。

```
import java.util.Random;

/**
 * Created by Administrator on 2016/4/27.
 */

class Initable{
    static final int staticFinal = 47;
    static final int staticFinal2 = ClassInitialization.rand.nextInt(1000);
    static {
        System.out.println("Initializing Initable");
    }
}

class Initable2 {
    static int staticNonFinal = 147;
    static {
        System.out.println("Initializing Initable2");
    }
}

class Initable3 {
    static int staticNonFinal = 74;
    static {
        System.out.println("Initializing Initable3");
    }
}

public class ClassInitialization {
    public static Random rand = new Random(47);

    public static void main(String[] args) throws ClassNotFoundException {
        Class initable = Initable.class;
        System.out.println("After creating Initable ref");
        // Does not trigger initialization
        System.out.println(Initable.staticFinal);
        // Does trigger initialization
        System.out.println(Initable.staticFinal2);
        // Dose trigger initialization
        System.out.println(Initable2.staticNonFinal);
        Class initable3 = Class.forName("com.oneapm.si.rtti.Initable3");
        System.out.println("After creating Initable3 ref");
        System.out.println(Initable3.staticNonFinal);
    }
}
```
