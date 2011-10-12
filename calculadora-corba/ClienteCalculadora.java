import CalculadoraApp.*;
import org.omg.CosNaming.*;
import org.omg.CosNaming.NamingContextPackage.*;
import org.omg.CORBA.*;

public class ClienteCalculadora
{
  static Calculadora calculadoraImpl;

  public static void main(String args[])
    {
      try{
        // crea e inicializa el ORB
        ORB orb = ORB.init(args, null);

        // obtiene la raiz del nombre del contexto 
        org.omg.CORBA.Object objRef =  orb.resolve_initial_references("NameService");
        NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);
 
        String name = "Calculadora";
        calculadoraImpl = CalculadoraHelper.narrow(ncRef.resolve_str(name));

        //llamadas al servidor 

        System.out.println( calculadoraImpl.suma(3.5,3.5) );
        System.out.println( calculadoraImpl.division(3.5,3.5) );
        System.out.println( calculadoraImpl.multiplicacion(3.5,3.5) );
        System.out.println( calculadoraImpl.resta(3.5,3.5) );

	} catch (Exception e) {
          System.out.println("ERROR : " + e) ;
	  e.printStackTrace(System.out);
	  }
    }

}

