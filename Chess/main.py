''' Key-value storage 
Version 1.0.0
Create main functions for project
'''


import os
import tempfile

storage_path = os.path.join(tempfile.gettempdir(), 'storage data')
with open (storage_path, 'w') as f:
    
 
