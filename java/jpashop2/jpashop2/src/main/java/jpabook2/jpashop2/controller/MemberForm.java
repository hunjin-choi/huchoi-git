package jpabook2.jpashop2.controller;

import lombok.Getter;
import lombok.Setter;

import javax.validation.constraints.NotEmpty;

@Getter @Setter
public class MemberForm {
    @NotEmpty(message = "회원이름은 필수입니다")//validation
    private String name;

    private String city;
    private String street;
    private String zipcode;
}
