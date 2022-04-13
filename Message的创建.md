# Message创建方式

创建Message对象的时候,有三种方式,分别为:
```java
Message msg = new Message();
Message msg1 = Message.obtain();
Message msg2 = handler.obtainMessage();
```

## 使用方法
```java
public class MainActivity extends Activity {

    private Handler handler1 = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            Toast.makeText(MainActivity.this, "hanlder1", Toast.LENGTH_SHORT).show();
            super.handleMessage(msg);
        }
    };
    ;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        new Thread(new Runnable() {
            @Override
            public void run() {
//                Message msg = new Message();
//                Message msg2 = Message.obtain();
                Message msg1 = handler1.obtainMessage();
                msg1.arg1 = 1;
                handler1.sendMessage(msg1);
            }
        }).start();
    }
}
```

## 源码

### 1 new

直接new初始化一个Message的对象
```java
Message msg = new Message();
```

### 2 Message.obtain()

从Message池中返回一个新的Message实例
```java
public static Message obtain() {
    synchronized (sPoolSync) {
        if (sPool != null) {
            Message m = sPool;
            sPool = m.next;
            m.next = null;
            m.flags = 0; // clear in-use flag
            sPoolSize--;
            return m;
        }
    }
    return new Message();
}
```

### 3 handler.obtainMessage()  
如果看源码的话就会发现`handler.obtainMessage()`调用的还是`Message.obtain()`方法,都是先从池中获取对象,如果池子中有对象就抽一个用,没有的话就new一个
```java
public final Message obtainMessage()
{
    return Message.obtain(this);
}

public static Message obtain(Handler h) {
    Message m = obtain();
    m.target = h;

    return m;
}

public static Message obtain(Handler h, int what) {
    Message m = obtain();
    m.target = h;
    m.what = what;

    return m;
}


public static Message obtain() {
    synchronized (sPoolSync) {
        if (sPool != null) {
            Message m = sPool;
            sPool = m.next;
            m.next = null;
            m.flags = 0; // clear in-use flag
            sPoolSize--;
            return m;
        }
    }
    return new Message();
}
```

### 注意

使用handler.obtainMessage()创建message对象时,虽然底层也是调用的Message.obtain(),但是handler.obtainMessage()可能会报空指针异常,原因可能是handler未初始化或handler置空被GC回收资源了  
具体参考:
