package hello.core;

import hello.core.discount.DiscountPolicy;
import hello.core.discount.FixDiscountPolicy;
import hello.core.discount.RateDiscountPolicy;
import hello.core.member.MemberRepository;
import hello.core.member.MemberService;
import hello.core.member.MemberServiceImpl;
import hello.core.member.MemoryMemberRepository;
import hello.core.order.OrderService;
import hello.core.order.OrderServiceImpl;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

//@Configuration
public class AppConfig {
    @Bean
    public MemberService memberService() {
        return new MemberServiceImpl(getMemberRepository());
    }
    @Bean
    public OrderService orderService(){
        return new OrderServiceImpl(getMemberRepository(), getDiscountPolicy());
    }
    @Bean
    public DiscountPolicy getDiscountPolicy() {
        return new RateDiscountPolicy();
        //return new FixDiscountPolicy();
    }67
    @Bean
    public MemberRepository getMemberRepository() {
        System.out.println("이게 호출이 되면 안됩니다\n\n\n\n\n\n\n");
        return new MemoryMemberRepository();
    }
}