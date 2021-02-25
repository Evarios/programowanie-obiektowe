package customer;

public class Customer{
    private String name;
    private String PESEL;
    public Customer(){}
    public Customer(String s){
        this.name = s;
    }
    public Customer(String s, String pesel){
        this.name = s;
        this.PESEL = pesel;
    }
    public String getName(){
        return this.name;
    }
    public void setPesel(String pesel){
        this.PESEL = pesel;
    }
    public String readPesel(){
        return this.PESEL;
    }
    @Override //przesłaniamy metodę,
    public boolean equals(Object c){
        Customer customerTest = (Customer)c;
        if(this.getClass() == customerTest.getClass()){
            if(this.name == customerTest.getName()){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
}