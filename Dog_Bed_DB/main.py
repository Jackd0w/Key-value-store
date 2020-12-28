'''
Key-value storage
version 1.0.0
'''

import argparse
import json
import os
import tempfile

def read_data(storage_path):
    # Прерываем, если пути не существует
    if not os.path.exists(storage_path):
        return {}
    # Открываем на чтение    
    with open(storage_path, 'r') as file:
        raw_data = file.read()
        if raw_data:
            return json.loads(raw_data)
        return {}

def write_data(storage_path, data):
    with open(storage_path, 'w') as f:
        f.write(json.dumps(data))


