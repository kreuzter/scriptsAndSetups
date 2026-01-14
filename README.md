Add `source <path-to-this-directory>/sciptsAndSetups/.*rc` to the `.bashrc` file. All files containing additional aliases are then sourced with the `.bashrc` file.

To use the python setup:
``` python
import sys
sys.path.append(" <path-to-this-directory>/scriptsAndSetups/pythonScripts/")
import plotsSetup as ps

ps.update_rcParams(3)
```
