/* Demonstrating how to read from a text file
   Anderson, Franceschi
*/

import java.util.Scanner;
import java.io.File;
import java.io. FileNotFoundException;


public class ReadTextFile
{
  public static void main( String [ ] args )
  {
    try
    {
       Scanner file = new Scanner( new File ( "dataFile.txt" ) );

       while ( file.hasNext( ) ) // test for the end of the file
       {
          String stringRead = file.nextLine( );  // read a line
          System.out.println( stringRead );  // print the line read
       }

       // release resources associated with dataFile.txt
       file.close( );
    }



    
    catch ( FileNotFoundException fnfe )
    {
      System.out.println( "El archivo no existe" );
    }

    catch ( Exception ioe )
    {
      ioe.printStackTrace( );
    }

  }
}