bool isMatch(char* s, char* p) {    
    printf(" match s=%s,p=%s\n", s, p);
    char *t;

    while(true){
        printf("循环匹配 %s,%s\n",s,p);
        //检查当前匹配符
        switch(*p){
            //匹配符结尾
            case '\0':
                //如果目标串也是结束符返回true，否则返回false
                //if target string is endding return true, else return false
                if(*s==0) return true;
                else return false;
                break;
            //匹配0-多个任意字符
            case '*':
                //first, find next special char(not * and ?) from partten
                // when found '*' before special char, do nothing, '*' == '**'
                // each found '?' before special char, least match char count add 1, and check target string whether end.
                int least = 0;
                while(true){
                    switch(*(p+1)){
                        case '*':
                            p++;
                            continue;
                        case '?':
                            if(*(s)=='\0'){
                                return false;
                            }
                            least++;
                            s++;
                            continue;                        
                    }
                    //if run to here, found the char
                    //find the char from target string
                    return false;
                    //while()
                    //break;
                }
                break;
            //匹配单个任意字符
            case '?':
                //if target string is ending return false, else check next char
                if(*s==0) return false;
                s++;p++;
                continue;
                break;
            //其余情况为匹配指定字符
            default:
                //如果匹配则继续检查下一个匹配符，
                if(*s==*p){
                    s++;p++;
                    continue;
                }
                //如果不匹配，返回false
                else{
                    return false;
                }
        }
    }
        /*
        if(*p=='*'){
            if(*(p+1)==0){
                return true;
            }
            else if(*(p+1)=='*'){
                p++;
                continue;
            }
            t = s;
            //printf("t=%d,p+1=%d\n", *t, *(p+1));
            while(true){
                if(*t==0)return false;
                if(*t==*(p+1)){
                    if(isMatch(t, p+1)){
                        printf(" is match %s %s\n", t, p+1);
                        return true;
                    }else{
                        printf(" isn't match %s %s\n", t, p+1);
                    }
                }
                t++;
                //printf("t=%d,p+1=%d\n", *t, *(p+1));

            }
        }else if(*p=='?' || *s==*p){
            s++;
            p++;
        }else if(*s==0 || *p==0){
            break;
        }
        break;
    }
    if(*s==0 && *p==0){
        return true;
    }
    return false;*/
}
