#!/bin/sh

sed -i '' 's/new wxToolBar.*$/wxFrame::CreateToolBar(wxTB_TEXT);/g' Squoosh.cpp