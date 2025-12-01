surfaceFieldValue1
{
    // Mandatory entries (unmodifiable)
    type            surfaceFieldValue;
    libs            (fieldFunctionObjects);

    // Mandatory entries (runtime modifiable)
    fields          (p);
    operation       none;
    regionType      patch;
    name            blade_suction;
    surfaceFormat   raw;

    writeFields     true;
    scalingFactor   1.0;
    writePrecision  8;
    writeToFile     true;
    useUserTime     true;
    region          region0;
    enabled         true;
    log             true;

    executeControl  writeTime;
    writeControl    writeTime;
}
surfaceFieldValue2
{
    // Mandatory entries (unmodifiable)
    type            surfaceFieldValue;
    libs            (fieldFunctionObjects);

    // Mandatory entries (runtime modifiable)
    fields          (p);
    operation       none;
    regionType      patch;
    name            blade_pressure;
    surfaceFormat   raw;

    writeFields     true;
    scalingFactor   1.0;
    writePrecision  8;
    writeToFile     true;
    useUserTime     true;
    region          region0;
    enabled         true;
    log             true;

    executeControl  writeTime;
    writeControl    writeTime;
}
surfaceFieldValue3
{
    // Mandatory entries (unmodifiable)
    type            surfaceFieldValue;
    libs            (fieldFunctionObjects);

    // Mandatory entries (runtime modifiable)
    fields          (p);
    operation       none;
    regionType      patch;
    name            inlet;
    surfaceFormat   raw;

    writeFields     true;
    scalingFactor   1.0;
    writePrecision  8;
    writeToFile     true;
    useUserTime     true;
    region          region0;
    enabled         true;
    log             true;

    executeControl  writeTime;
    writeControl    writeTime;
}
surfaceFieldValue4
{
    // Mandatory entries (unmodifiable)
    type            surfaceFieldValue;
    libs            (fieldFunctionObjects);

    // Mandatory entries (runtime modifiable)
    fields          (p);
    operation       none;
    regionType      patch;
    name            outlet;
    surfaceFormat   raw;

    writeFields     true;
    scalingFactor   1.0;
    writePrecision  8;
    writeToFile     true;
    useUserTime     true;
    region          region0;
    enabled         true;
    log             true;

    executeControl  writeTime;
    writeControl    writeTime;
}
forces1
{
    // Mandatory entries
    type            forces;
    libs            ("libforces.so");
    patches         ("blade*|wall*");


    // Optional entries

    // Field names
    p               p;
    U               U;
    rho             rho;
    CofR            (0 0 0);
    origin          (0 0 0);
    // Reference pressure [Pa]
    pRef            0;

    // Include porosity effects?
    porosity        no;

    // Store and write volume field representations of forces and moments
    writeFields     false;

    executeControl  writeTime;
    writeControl    writeTime;
}
massFlux1
{
  type            exprField;
  libs            (fieldFunctionObjects);
  field           massFlux;
  expression      "U.x()*rho";
  dimensions      [ kg/(s*m*m) ];

  executeControl  writeTime;
  writeControl    writeTime;
}
