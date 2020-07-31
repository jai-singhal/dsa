// https://www.interviewbit.com/problems/simplify-directory-path/


string simplifyPath(string A) {
    stack<string> dir_stack;
    string dir = "";
    for(auto s: A){
        if(s == '/'){
            if(dir == ".."){
                if(!dir_stack.empty())
                    dir_stack.pop();
            }
            else{
                if(dir != "." && dir.length() > 0)
                    dir_stack.push(dir);
            }
            
            dir = "";
        }
        else
            dir += s;
    }
    
    if(dir == ".."){
        if(!dir_stack.empty())
            dir_stack.pop();
    }
    else{
        if(dir != "." && dir.length() > 0)
            dir_stack.push(dir);
    }
        
    string final_dir = "";
    
    if(dir_stack.empty())
        return "/";
        
    while(!dir_stack.empty()){
        final_dir =  "/" + dir_stack.top() + final_dir;            
        dir_stack.pop();
    }

    return final_dir;
}
