package CalculadoraApp;


public abstract class CalculadoraPOA extends org.omg.PortableServer.Servant
 implements CalculadoraApp.CalculadoraOperations, org.omg.CORBA.portable.InvokeHandler
{

  // Constructores

  private static java.util.Hashtable _methods = new java.util.Hashtable ();
  static
  {
    _methods.put ("suma", new java.lang.Integer (0));
    _methods.put ("resta", new java.lang.Integer (1));
    _methods.put ("multiplicacion", new java.lang.Integer (2));
    _methods.put ("division", new java.lang.Integer (3));
  }

  public org.omg.CORBA.portable.OutputStream _invoke (String $method,
                                org.omg.CORBA.portable.InputStream in,
                                org.omg.CORBA.portable.ResponseHandler $rh)
  {
    org.omg.CORBA.portable.OutputStream out = null;
    java.lang.Integer __method = (java.lang.Integer)_methods.get ($method);
    if (__method == null)
      throw new org.omg.CORBA.BAD_OPERATION (0, org.omg.CORBA.CompletionStatus.COMPLETED_MAYBE);

    switch (__method.intValue ())
    {
       case 0:  // CalculadoraApp/Calculadora/suma
       {
         double a = in.read_double ();
         double b = in.read_double ();
         double $result = (double)0;
         $result = this.suma (a, b);
         out = $rh.createReply();
         out.write_double ($result);
         break;
       }

       case 1:  // CalculadoraApp/Calculadora/resta
       {
         double a = in.read_double ();
         double b = in.read_double ();
         double $result = (double)0;
         $result = this.resta (a, b);
         out = $rh.createReply();
         out.write_double ($result);
         break;
       }

       case 2:  // CalculadoraApp/Calculadora/multiplicacion
       {
         double a = in.read_double ();
         double b = in.read_double ();
         double $result = (double)0;
         $result = this.multiplicacion (a, b);
         out = $rh.createReply();
         out.write_double ($result);
         break;
       }

       case 3:  // CalculadoraApp/Calculadora/division
       {
         double a = in.read_double ();
         double b = in.read_double ();
         double $result = (double)0;
         $result = this.division (a, b);
         out = $rh.createReply();
         out.write_double ($result);
         break;
       }

       default:
         throw new org.omg.CORBA.BAD_OPERATION (0, org.omg.CORBA.CompletionStatus.COMPLETED_MAYBE);
    }

    return out;
  } 

  // operariones CORBA::Object 
  private static String[] __ids = {
    "IDL:CalculadoraApp/Calculadora:1.0"};

  public String[] _all_interfaces (org.omg.PortableServer.POA poa, byte[] objectId)
  {
    return (String[])__ids.clone ();
  }

  public Calculadora _this() 
  {
    return CalculadoraHelper.narrow(
    super._this_object());
  }

  public Calculadora _this(org.omg.CORBA.ORB orb) 
  {
    return CalculadoraHelper.narrow(
    super._this_object(orb));
  }


} // class CalculadoraPOA
