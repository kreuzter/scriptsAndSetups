//wallShearStress1
//{
//  type            wallShearStress;
//  libs            (fieldFunctionObjects);
//  patches         ("blade*|wall*");
//
//    executeControl  runTime;
//    executeInterval 1e-2;
//    writeControl    runTime;
//    writeInterval   1e-2;
//}

/*
surfaces1
{
    type            surfaces;
    libs            (sampling);
    fields          (U p);

    surfaceFormat   vtk;

    surfaces
    {
        downstreamTraversingPlane
        {
            type        cuttingPlane;
            planeType pointAndNormal;
            pointAndNormalDict
            {
              point       (0.0945 0 0);
              normal      (1 0 0);
            }
            point       (0.0945 0 0);
            normal      (1 0 0);
        }
        //centralPlane
        //{
        //    type        cuttingPlane;
        //    planeType pointAndNormal;
        //    pointAndNormalDict
        //    {
        //      point       (0 0 0);
        //      normal      (0 0 1);
        //    }
        //    point       (0 0 0);
        //    normal      (0 0 1);
        //}
    }
  
    executeControl  runTime;
    executeInterval 1e-4;
    writeControl    runTime;
    writeInterval   1e-4;
}
*/

probes1
{
    // Mandatory entries
    type                probes;
    libs                (sampling);
    probeLocations      ((0.0682 0.082531 0.0));
    fields              (U p);

    executeControl  timeStep;
    executeInterval 1;
    writeControl    timeStep;
    writeInterval   1;
}

surfaceFieldValue1
{
    type            surfaceFieldValue;
    libs            (fieldFunctionObjects);

    fields          (T);
    operation       areaAverage;
    regionType      patch;
    name            inlet;

    writeFields     false;

    executeControl  timeStep;
    executeInterval 1;
    writeControl    timeStep;
    writeInterval   1;
}
