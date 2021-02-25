package recycling;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.TreeMap;
import java.util.Scanner;
public class Wezel{
@Deprecated
@Override
protected void finalize() throws Throwable {
System.out.println("Finalizowanie objektu");
super.finalize();
}
ArrayList<Wezel> polaczenia = new ArrayList<>();
HashMap<Wezel, Boolean> polaczeniaHash = new HashMap<>();
TreeMap<Wezel, Boolean> polaczeniaTree = new TreeMap<>();
public void dodajPolaczenie(Wezel w){
    this.polaczenia.add(w);
}

public void dodajPolaczenieHash(Wezel w, Boolean b){
    this.polaczeniaHash.put(w, b);
}
public void dodajPolaczenieTree(Wezel w, Boolean b){
    this.polaczeniaTree.put(w, b);
}
public static void main (String[] args) {
    Scanner s = new Scanner(System.in);
    for (int i = 0; i <= 1000000; i++){ // przy 10000 się nie finalozowało, to dlatego, że metoda finalize jest odpalana w momencie kiedy garbage collector zbiera i usuwa nieużywane elementy, więc widać, że zaczął działać dopiero jak zostało utworzone więcej elementów
        Wezel w1 = new Wezel();
        Wezel w2 = new Wezel();
        //w1.dodajPolaczenieTree(w2, true);
        //w2.dodajPolaczenieTree(w1, true);
        //w1.dodajPolaczenieHash(w2, true);
        //w2.dodajPolaczenieHash(w1, true);
        w1.dodajPolaczenie(w2);
        w2.dodajPolaczenie(w1);
    }
    s.nextLine();
    s.close();
}
}