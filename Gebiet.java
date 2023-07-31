class Gebiet extends java.lang.Object {
    private final int plz;
    private final String ort;

    public Gebiet(int plz, String ort) {
        super();
        // TODO validate constructor parameters
        this.plz = plz;
        this.ort = ort;
    }

    @Override
    public boolean equals(Object obj) {
        return obj instanceof Gebiet that
            && this.plz == that.plz
            && this.ort.equals(that.ort);
    }
}

class Main {
    public static void main(String[] args) {
        Gebiet a = new Gebiet(33615, "Bielefeld");
        Gebiet b = new Gebiet(33615, "Bielefeld");

        assert(a != b);      // Gebiet
        assert(a.equals(b)); // Gebiet
/*
        +-------------+   +-------------+
        |  33615      |   |  33615      |
        | "Bielefeld" |   | "Bielefeld" |
        +-------------+   +-------------+
          ^       ^         ^   ^     ^
          |       |         |   |     |
          |     +-|-+     +-|-+ |     |
          |   a | ° +   b | ° | |     |
          |     +---+     +---+ |     |
          |                     |     |
        +-|-+                 +-|-+ +-|-+
        | ° | this        obj | ° | | ° | that
        +---+                 +---+ +---+
*/
        a = b;
        assert(a == b);
        assert(a.equals(b));
/*
                          +-------------+
          +-------------> |  33615      |
          |       +-----> | "Bielefeld" |
          |       |       +-------------+
          |       |         ^   ^     ^
          |       |         |   |     |
          |     +-|-+     +-|-+ |     |
          |   a | ° +   b | ° | |     |
          |     +---+     +---+ |     |
          |                     |     |
        +-|-+                 +-|-+ +-|-+
        | ° | this        obj | ° | | ° | that
        +---+                 +---+ +---+
*/
    }
}

/*
JLS 4.3.1

The reference values (often just references) are pointers to objects,  
and a special null reference, which refers to no object.



"The Java Programming Language"
Ken Arnold, James Gosling, David Holmes

The Java programming language does not pass objects by reference;
it passes object references by value.  

There is exactly one parameter passing mode
– pass by value –
and that helps keep things simple.
*/
