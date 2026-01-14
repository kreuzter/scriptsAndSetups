#includeFunc "MachNo"
#includeFunc "yPlus"

turbulenceFields1
{
  // Mandatory entries (unmodifiable)
  type            turbulenceFields;
  libs            (fieldFunctionObjects);

  fields          (I L); // turbulence intensity and length scale

  executeControl  writeTime;
  writeControl    writeTime;
}
totalPressure_
{
  type            exprField;
  libs            (fieldFunctionObjects);
  field           p0;
  expression      "p*pow( 2/( pow(Ma, 2)*0.4 + 2 ) , -1.4/0.4)";
  dimensions      [ Pa ];

  executeControl  writeTime;
  writeControl    writeTime;
}
entropy_
{
  type            exprField;
  libs            (fieldFunctionObjects);
  field           entropy;
  expression      "1004.5*log(T) - 287.1*log(p)";
  dimensions      [ J/K ];

  executeControl  writeTime;
  writeControl    writeTime;
}
massFlux_
{
  type            exprField;
  libs            (fieldFunctionObjects);
  field           massFlux;
  expression      "U.x()*rho";
  dimensions      [ kg/(s*m*m) ];

  executeControl  writeTime;
  writeControl    writeTime;
}
flowAngle_
{
  type            exprField;
  libs            (fieldFunctionObjects);
  field           flowAngle;
  expression      "atan2( U.y(), U.x() )*180/3.1416";
  dimensions      [ Hz ];

  executeControl  writeTime;
  writeControl    writeTime;
}
eulerInvariantI_
{
  type            exprField;
  libs            (fieldFunctionObjects);
  field           eulerInvariantI;
  expression      "mag(U) - (2*sqrt(1.4*287.0*T))/(0.4)";
  dimensions      [ m/s ];

  executeControl  writeTime;
  writeControl    writeTime;
}
eulerInvariantII_
{
  type            exprField;
  libs            (fieldFunctionObjects);
  field           eulerInvariantII;
  expression      "log(p/pow(rho,1.4))";
  dimensions      [ m/s ];

  executeControl  writeTime;
  writeControl    writeTime;
}
eulerInvariantIII_
{
  type            exprField;
  libs            (fieldFunctionObjects);
  field           eulerInvariantIII;
  expression      "mag(U) + (2*sqrt(1.4*287.0*T))/(0.4)";
  dimensions      [ m/s ];

  executeControl  writeTime;
  writeControl    writeTime;
}

isentropicMach1
{
  type coded;
  libs (utilityFunctionObjects);
  name isentropicMach;
  codeWrite
    #{
      
      const volScalarField& p  = mesh().lookupObject<volScalarField>("p" );
      const volScalarField& p0 = mesh().lookupObject<volScalarField>("p0");

      const dictionary& thermophysicalProperties = p.db().lookupObject<IOdictionary>
      (
        "thermophysicalProperties"
      );

      dictionary mixture
      (
        thermophysicalProperties.subDict("mixture")
      );

      dictionary thermodynamics
      (
        mixture.subDict("thermodynamics")
      );

      dictionary specie
      (
        mixture.subDict("specie")
      );

      const scalar Cp = readScalar(thermodynamics.lookup("Cp"));
      const scalar M  = readScalar(specie.lookup("molWeight"));
      const scalar R  = (8314.46261815324);
      const scalar r  = R/M;
      const scalar kappa  = Cp/(Cp-r);    

      const label inletId = p.mesh().boundaryMesh().findPatchID("inlet");

      const scalarField& magSfIn = p.mesh().magSf().boundaryField()[inletId];
      dimensionedScalar p01 
      (
        "p01", 
        dimensionSet(1, -1, -2, 0, 0, 0, 0), 
        (gSum(p0.boundaryField()[inletId]*magSfIn) / gSum(magSfIn))
      );

      const volScalarField Ma_is  ("Ma_is" , sqrt( (pow( max(p01/p, scalar(1.0)) , (kappa-1.)/kappa) -1. )*(2./(kappa-1.)) ) );
      Ma_is.write();
    #};

  executeControl  writeTime;
  writeControl    writeTime;
}
