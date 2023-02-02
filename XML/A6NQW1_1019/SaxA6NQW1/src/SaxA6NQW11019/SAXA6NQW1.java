//plusz feladat old meg, hogy az adatok egymás mellé (egy sorba kerüljenek)!

package SaxA6NQW11019;


import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import java.io.File;
import java.io.IOException;

public class SAXA6NQW1 {

    public static void main(String[] args){

        try{
            // Dokumentumolvasó létrehozása
            SAXParserFactory saxParserFactory = SAXParserFactory.newInstance();

            // példányosítja a SAX értelmezőt
            SAXParser saxParser = saxParserFactory.newSAXParser();

            // saját eseménykezelő objektum létrehozása
            SaxHandler handler = new SaxHandler();

            // dokumentum értelmezési folyamatának elinditása
            // a parse metódus első paramétere a beolvasandó XML fájl neve
            //AZ .xml FÁJLNAK A GYÖKÉRBEN KELL LENNIE!!
            saxParser.parse(new File("BSZK_kurzusfelvetel.xml"), handler);

        } catch (ParserConfigurationException | SAXException | IOException e) {
            e.printStackTrace();
        }
    }
}

//tartalomkezelő keret létrehozása + esemény- és hibakezelő metódus
class SaxHandler extends DefaultHandler {
    private int indent = 0;

    private String formatAttributes(Attributes attributes) {
        int attrLength = attributes.getLength();
        if(attrLength == 0) {
            return "";
        }
        StringBuilder sb = new StringBuilder(", {");
        for (int i = 0; i < attrLength; i++) {
            sb.append(attributes.getLocalName(i) + "=" + attributes.getValue(i));
            if(i < attrLength - 1) {
                sb.append(", ");
            }
        }
        sb.append("}");
        return sb.toString();
    }

    private void indent() {
        for (int i = 0; i < indent; i++) {
            System.out.print(" ");
        }
    }


// esemény kezelő metódusok létrehozása, startElement metódus

    //elem kezdete és vége
    @Override
    public void startElement(String uri, String localName, String qName, Attributes attributes) {
        indent++; //behúz mindent
        indent(); //start húzza be
        System.out.println(qName + formatAttributes(attributes) + " start");
    }

    //endElement metódust újraimplementáljuk
    @Override
    public void endElement(String uri, String localName, String qName) {
        indent(); //end húzza be
        indent--; //behúzás csökkentése
        System.out.println(qName + " end");
    }

    //szövegelem feldolgozása, characters metódust újraimplementáljuk
    @Override
    public void characters(char ch[], int start, int length) {
        String chars = new String(ch, start, length).trim();
        if(!chars.isEmpty()) {
            indent++; //behúz mindent
            indent(); //karakter behúzás
            indent--; //behúzás csökkentése
            System.out.println(chars);
        }
    }
}