# Pacos

php extend for nacos



## 安装

#### 下载编译

```shell
git clone https://github.com/zhenyangze/pacos
cd pacos
phpize
./configure --with-php-config=${PATh}
make
make install
```

#### 修改php.ini文件

```ini
extension=pacos.so

;1全局进程 2独立进程
pacos_run_mode=1
pacos_pid_file=/tmp/pacos.beat.test.pid
;心跳周期
pacos_period_time=10
;请求超时时间
pacos_http_timeout=3
;namespace可不写，默认为public
;pacos_namespace=sit
;1展示异常信息
pacos_display_error=1 
```



## 使用

### 一、动态配置

#### 初始化

```php
$config = new \Pacos\Config('http://localhost', '8848');
```



#### 1、获取配置

```php
$config->get(string $dataId, string $group = "DEFAULT_GROUP", $callback = null);
```

示例

```php
$config->get('nacos.example', 'com.alibaba.nacos');
$config->get('nacos.example', 'com.alibaba.nacos', function($dataId, $group) {
  return "没有获取配置信息，自定义返回";
});
```

#### 2、发布配置

```php
$config->set(string $dataId, string $group = "DEFAULT_GROUP", string $content);
```

示例

```php
$config->set('nacos.example', 'com.alibaba.nacos', "demo");
```

#### 3、删除配置

```php
$config->delete(string $dataId, string $group = "DEFAULT_GROUP")
```

示例

```php
$config->delete('nacos.example', 'com.alibaba.nacos');
```

#### 4、监听配置

```php
$config->listen(array $configs, int $timeout = 30)
```

示例

```php
$config->listen([
    [
        'dataId' => 'nacos.example',
        "group" => 'com.alibaba.nacos',
        'contentMd5' => md5("demo")
    ]
]);
```

#### 5、查询历史版本

```php
$config->search(string $dataId, string $group, int $pageNo = 1, int $pageSize = 100)
```

示例

```php
$config->search('nacos.example', 'com.alibaba.nacos');
```



### 二、服务注册与发现

#### 初始化

```php
$instance = new \Pacos\Instance('http://localhost', '8848');
```



#### 1、添加实例

```php
$instance->add(array $instance)
```

示例

```php
$instance->add([
    'ip' => '127.0.0.1',
    'port' => 80,
    'serviceName' => 'test1',
]);
```

#### 2、删除实例

```php
$instance->delete(string $serviceName, string $ip, int $port, string $clusterName = null, string $namespaceId = null)
```

示例

```php
$instance->delete("test", "127.0.0.1", "80");
```

#### 3、查询实例列表

```php
$instance->list(string $serviceName, string $namespaceId = null, array $clusters = [])
```

示例

```estphp
$instance->list("test");
```

#### 4、查询实例详情

```php
$instance->get(string serviceName, string ip, int port, string namespaceId = null, string cluster = null, bool healthyOnly = false)
```

示例

```php
$instance->get("test", "127.0.0.1", "80");
```

#### 5、按权重获取实例

```php
$instance->select(string $serviceName, string $namespaceId = null)
```

示例

```php
$instance->select("test");
```

#### 6、调用实例方法

```php
$instance->call(string $serviceName, string $method, string $uri, array $options = [], string $namespaceId = null)
```

示例

```php
$instance->call("test", "GET", "/api/user/info");
```

#### 7、更新实例

```php
$instance->update(array $instance)
```

示例

```php
$instance->update([
    'ip' => '127.0.0.1',
    'port' => 80,
    'serviceName' => 'test',
]);
```

#### 8、发送心跳(手动)

```php
$instance->beat(array $beatInfo)
```

示例

```php
$instance->beat([
    'ip' => '127.0.0.1',
    'port' => 80,
    'serviceName' => 'test1',
]);
```

#### 9、批量注册实例，并周期性发送心跳

```php
$instance->register(string $uniqueName, array $instanceList)
```

示例

```php
$instance->register(__FILE__, [
    [
        'ip' => '127.0.0.1',
        'port' => 80,
        'serviceName' => 'php.test',
    ],
    [
        'ip' => '127.0.0.1',
        'port' => 80,
        'serviceName' => 'php.test2',
    ]
]);
```

