//
//  NotesViewController.swift
//  Notes
//
//  Created by Mouhamed Sourang on 4/8/20.
//  Copyright © 2020 Mouhamed Sourang. All rights reserved.
//


import UIKit
class NoteViewController: UIViewController {
    
    var note: Note!
    @IBOutlet var textView: UITextView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        textView.text = note.contents
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        note.contents = textView.text
        NotesManager.main.save(note: note)
    }
    
    
    @IBAction func deleteNotes() {
        NotesManager.main.delete(note: note)
        navigationController?.popViewController(animated: true)
    }
    
}
