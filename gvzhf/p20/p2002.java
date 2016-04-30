import java.io.*;
import java.util.*;



public class p2002 {
    public static class Record{
        public Record(String _password){
            password = _password;
            loggined = false;
        }
        public String password;
        public boolean loggined;

    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        HashMap<String, Record> hm = new HashMap<String, Record>();

        int n = in.nextInt();
        in.nextLine();

        for (int i = 0; i < n; i++) {
            String s = in.nextLine();
            String[] parts = s.split(" ");
            String cmd = parts[0];
            String login = parts[1];
            String password = "";
            if(parts.length>2)
                password = parts[2];
            if(cmd.equals("register")){
                if(hm.containsKey(login)){
                    out.println("fail: user already exists");
                }else{
                    hm.put(login, new Record(password));
                    out.println("success: new user added");
                }
            }else if(cmd.equals("login")){
                if(!hm.containsKey(login)){
                    out.println("fail: no such user");
                }else{
                    Record r = hm.get(login);
                    if(!r.password.equals(password)){
                        out.println("fail: incorrect password");
                    }else{
                        if(r.loggined){
                            out.println("fail: already logged in");
                        }else{
                            r.loggined = true;
                            out.println("success: user logged in");
                        }
                    }
                }
            }else if(cmd.equals("logout")) {
                if(!hm.containsKey(login)){
                    out.println("fail: no such user");
                }else{
                    Record r = hm.get(login);
                        if(!r.loggined){
                            out.println("fail: already logged out");
                        }else{
                            r.loggined = false;
                            out.println("success: user logged out");
                        }
                }
            }else{
                //something is wrong
            }
        }
        out.flush();
    }
}