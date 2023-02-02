package hu.medvetojas;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {

    public static void main(String[] args) {
        // try-catch blokk ami kezeli azokat az eseteket amik nem SQL CREATE TABLE parancsok
        try {
            // scanner objektum az input beolvasásához
            Scanner scanner = new Scanner(System.in);
            String before, after;

            // felhasználói input bekérése
            System.out.println("Enter CREATE TABLE command: ");
            before = scanner.nextLine();

            // az utolsó ',' karakter kezelése
            // a regex elvár egy vesszőt minden sor végén
            // ha a felhasználó nem adta meg ezt a vesszőt, akkor a program megteszi helyette
            int indexOfLastBracket = before.lastIndexOf(")");
            after = before.substring(0, indexOfLastBracket) + ',' + before.substring(indexOfLastBracket);

            // regex a tábla nevére
            String varName = "[a-zA-Z_][a-zA-Z_$0-9]*";
            // adattípusok melynek vannak paraméterei
            String dataTypesMustParams = "((VARCHAR *\\( *[$0-9]+ *\\))|(VARBINARY *\\( *[$0-9]+ *\\)))";
            // adattípusok melynek nincsenek paraméterei
            String dataTypesMustNotParams = "((CHAR)|(BINARY)|(TINYBLOB)|(TINYTEXT)|(TEXT)|(MEDIUMTEXT)|(BLOB)"
                    + "|(MEDIUMBLOB)|(LONGTEXT)|(LONGBLOB)|(BIT)|(TINYINT)|(BOOL)|(BOOLEAN)|(SMALLINT)|(MEDIUMINT)"
                    + "|(INT)|(YEAR)|(TIME)|(TIMESTAMP)|(DATETIME)|(INTEGER)|(BIGINT)|(FLOAT)|(DOUBLE)|(DECIMAL)|(DEC))";
            // kiválasztjuk mindkét adattípus fajtát (paraméteres és nem paraméteres)
            String type = "((" + dataTypesMustParams + ")|(" + dataTypesMustNotParams + "( *\\( *[$0-9]+ *\\))?)) *, *";

            // a végső regex kifejezés
            String exp = "^create *table *" + varName + " *\\( *(" + varName + " +" + type + ")+? *\\) *;$";

            // compileoljuk a végső regexet
            Pattern p = Pattern.compile(exp, Pattern.CASE_INSENSITIVE);
            // a felhasználói bevitellel matcheljük a regexünket
            Matcher m = p.matcher(after);
            // boolean (logikai) változóba eltároljuk, hogy érvényes-e szintaktikailag a CREATE TABLE input, vagy nem
            boolean matchFound = m.matches();

            // output kiírása a logikai érték alapján
            if (matchFound)
                System.out.println("\n=> Valid syntax \n");
            else
                System.out.println("\n=> Invalid syntax \n");
        }catch (Exception e){
            System.out.println("\n=> Invalid syntax \n");
        }
    }
}