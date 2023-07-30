import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;
import java.util.TreeSet;

class Gebiet implements Comparable<Gebiet> {
    private final int plz;
    private final String ort;

    public Gebiet(int plz, String ort) {
        // TODO validate constructor parameters
        this.plz = plz;
        this.ort = ort;
    }

    public int plz() {
        return plz;
    }

    public String ort() {
        return ort;
    }

    @Override
    public String toString() {
        return plz + " " + ort;
    }

    @Override
    public boolean equals(Object obj) {
        return obj instanceof Gebiet that
            && this.plz == that.plz
            && this.ort.equals(that.ort);
    }

    @Override
    public int hashCode() {
        return plz * 31 + ort.hashCode();
    }

    @Override
    public int compareTo(Gebiet that) {
        if (this.plz < that.plz) return -1;
        if (that.plz < this.plz) return +1;

        return this.ort.compareTo(that.ort);
    }
}

class Main {
    public static void main(String[] args) {
        List<Gebiet> liste = new ArrayList<Gebiet>();
        liste.add(new Gebiet(33615, "Bielefeld"));
        System.out.println(liste);
        System.out.println(liste.contains(new Gebiet(33615, "Bielefeld")));

        Set<Gebiet> menge = new HashSet<Gebiet>();
        menge.add(new Gebiet(33615, "Bielefeld"));
        System.out.println(menge);
        System.out.println(menge.contains(new Gebiet(33615, "Bielefeld")));

        Set<Gebiet> baum = new TreeSet<Gebiet>();
        baum.add(new Gebiet(33615, "Bielefeld"));
        System.out.println(baum);
        System.out.println(baum.contains(new Gebiet(33615, "Bielefeld")));
    }
}
