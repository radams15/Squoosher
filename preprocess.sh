#!/bin/sh

perl -i -pe 's/new wxToolBar.*$/wxFrame::CreateToolBar(wxTB_TEXT);/g' Squoosh.cpp