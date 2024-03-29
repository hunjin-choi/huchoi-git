package hello.core.common;

import org.springframework.context.annotation.Scope;
import org.springframework.context.annotation.ScopedProxyMode;
import org.springframework.stereotype.Component;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;
import java.util.UUID;

@Scope(value = "request", proxyMode = ScopedProxyMode.TARGET_CLASS)
@Component
public class MyLogger {
    private String uuid;
    private String requestURL;

    public void setRequestURL(String requestURL) {
        this.requestURL = requestURL;
    }

    public void log(String msg){
        System.out.println("[" + uuid + "]" + "[" + requestURL + "]" + msg);
    }

    @PostConstruct
    void init(){
        uuid = UUID.randomUUID().toString();
        System.out.println("[" + uuid + "]" + "request scope created" + this);

    }

    @PreDestroy
    void destory(){
        System.out.println("[" + uuid + "]" + "request scope close" + this);
    }
}
