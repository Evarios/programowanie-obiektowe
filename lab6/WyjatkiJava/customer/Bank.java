package customer;
import java.util.*;

public class Bank implements SearchAccounts, SearchCustomers{
    ArrayList<Customer> customers = new ArrayList<Customer>();
    ArrayList<Account> accounts = new ArrayList<Account>();
    @Override
    public Customer findByName(String name) throws CustomerNotFoundException{
        for(Customer c : customers){
            if(c.getName()==name){
                return c;
            }
        }
        throw new CustomerNotFoundException(name);
    }
    @Override
    public Account findByNumber(int num) throws AccountNotFoundException{
        for(Account account : accounts){
            if (account.getNumber() == num){
                return account;
            }
        } 
        throw new AccountNotFoundException(num);
    }
    @Override
    public ArrayList<Account> findAllCustomerAccounts(Customer cust) throws AccountNotFoundException{
        ArrayList<Account> foundAccounts = new ArrayList<>();
        for(Account account : accounts){
            if (account.getCustomer().equals(cust)){
                foundAccounts.add(account);
            }
        }
        if(foundAccounts.isEmpty()){
            throw new AccountNotFoundException("Nie znaleziono zadnego konta nalezacego do" + cust.getName());
        }
        else{
            return foundAccounts;
        }
    }
    public void addNewCustomer(Customer cust){
        customers.add(cust);
    }

    public void addNewAccount(Account acc){
        accounts.add(acc);
    }
}
