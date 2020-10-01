//
//  Notes.swift
//  Notes
//
//  Created by Mouhamed Sourang on 4/7/20.
//  Copyright © 2020 Mouhamed Sourang. All rights reserved.
//

import Foundation
import SQLite3


struct Note {
    
    let id: Int
    var contents: String
}

class NotesManager {
    var database: OpaquePointer!
    
    static let main =  NotesManager()
    private init () {
        
    }
    
    func connect() {
        
        if database != nil {
        }
        do {
            let databaseURL =  try FileManager.default.url(for: .documentDirectory, in: .userDomainMask, appropriateFor: nil, create: true).appendingPathComponent("notes.sqlite2")
            if  sqlite3_open(databaseURL.path, &database) == SQLITE_OK {
                if  sqlite3_exec(database, "CREATE TABLE IF NOT EXISTS notes (contents TEXT)", nil, nil, nil) == SQLITE_OK {
                    
                } else{
                    print("Could not connect")
                }
                
            } else {
                print("could not open database")
            }
        }
        catch _ {
            print("could note create notes")
        }
    }
    
    func create() -> Int {
        
        connect()
        var statement: OpaquePointer!
        if sqlite3_prepare_v2(database, "INSERT INTO notes (contents) VALUES ('New note')", -1, &statement, nil) != SQLITE_OK {
            print("Could Not Insert Note")
            return -1
        }
        if sqlite3_step(statement) != SQLITE_DONE {
            print("Could not create query")
            return -1
        }
        sqlite3_finalize(statement)
        return Int(sqlite3_last_insert_rowid(database))
    }
    
    func getAllNotes() -> [Note] {
        connect()
        var result: [Note] = []
        var statement: OpaquePointer!
        if sqlite3_prepare_v2(database, "SELECT rowid, contents FROM notes", -1, &statement, nil) != SQLITE_OK {
            print("Error Creating Select")
            return []
        }
        while sqlite3_step(statement) == SQLITE_ROW {
            result.append(Note(id: Int(sqlite3_column_int(statement, 0)), contents: String(cString:sqlite3_column_text(statement, 1))))
            
        }
        
        sqlite3_finalize(statement)
        return result
    }
    
    func save(note: Note) {
        connect()
        var statement:OpaquePointer!
        if sqlite3_prepare_v2(database, "UPDATE notes SET contents = ? WHERE rowid = ? ", -1, &statement, nil) != SQLITE_OK {
            print("Error Creating update statement")
        }
        sqlite3_bind_text(statement, 1, NSString(string: note.contents).utf8String, -1, nil)
        sqlite3_bind_int(statement, 2, Int32(note.id))
        if sqlite3_step(statement) != SQLITE_DONE {
            print ("Error Running Update")
        }
        sqlite3_finalize(statement)
        
    }
    
    // Delete Note function
    
    func delete(note: Note)  {
        connect()
        var statement:OpaquePointer!
        if sqlite3_prepare_v2(database, "DELETE FROM notes WHERE rowid = ?;", -1, &statement, nil) != SQLITE_OK {
            print("Could Note Delete Note")
        }
        sqlite3_bind_int(statement, 1, Int32(note.id))
        if sqlite3_step(statement) != SQLITE_DONE {
            print ("Error Running Update")
        }
        sqlite3_finalize(statement)
 }

}
