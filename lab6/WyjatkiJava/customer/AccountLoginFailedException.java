package customer;
import java.util.*;

public class AccountLoginFailedException extends Exception{
    static final long serialVersionUID = 1L;
    private int password;
    private String login;
    AccountLoginFailedException(){}
    AccountLoginFailedException(String errorMsg, String s, int passwd){
        super(errorMsg);
        login = s;
        password = passwd;
    }
    int getPassword(){
        return this.password;
    }
    String getLogin(){
        return this.login;
    }
}

interface SearchCustomers{
    Customer findByName(String name) throws CustomerNotFoundException;
}

interface SearchAccounts{
    Account findByNumber(int number) throws AccountNotFoundException;
    ArrayList<Account> findAllCustomerAccounts(Customer cust) throws AccountNotFoundException;
}

class CustomerNotFoundException extends Exception{
    static final long serialVersionUID = 2L;
    CustomerNotFoundException(){}
    CustomerNotFoundException(String name){
        super("Nie znaleziono klienta" + name);
    }
}

class AccountNotFoundException extends Exception{
    static final long serialVersionUID = 3L;
    AccountNotFoundException(){}
    AccountNotFoundException(int accNumber){
        super("Nie znaleziono konta o numerze" + accNumber);
    }
    AccountNotFoundException(String msg){
        super(msg);
    }
}