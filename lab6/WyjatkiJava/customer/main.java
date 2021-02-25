package customer;
import java.util.*;

public class main {
    public static void main(String[] args){
        try{
            Customer cust = new Customer("Wojtyla", "21371337");
            System.out.println("Nazwisko " + cust.getName() + " PESEL: " + cust.readPesel());
            Account acc = new Account(0,cust,2137,"JuanPablo");
            acc.login("test", 1234);
            System.out.println(acc.getBalance());

            Bank bank = new Bank();
            bank.addNewCustomer(cust);
            bank.addNewAccount(acc);
            bank.findByNumber(2137);
            bank.findByName("JanPawel");
            ArrayList<Account> papiezaki = bank.findAllCustomerAccounts(cust);
            for(Account i : papiezaki){
                System.out.println("numer konta " + i.getNumber());
            }
            Account acc2 = bank.findByNumber(2137); // wyrzuca wyjątek

        }
        catch(AccountLoginFailedException|AccountNotFoundException|CustomerNotFoundException e){
            e.fillInStackTrace();
            System.out.println(e.getMessage());
            e.printStackTrace();
        }
    }
}
