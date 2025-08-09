#!/bin/bash
echo "Cleaning up old files..."
rm -f ../penguins-bootloaders*.*
ls ..
echo ""
echo "Your release is actually $(< ./release), update it if needed"