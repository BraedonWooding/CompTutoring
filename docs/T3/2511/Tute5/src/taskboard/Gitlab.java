package taskboard;

import java.util.ArrayList;
import java.util.List;

import taskboard.state.State;

public class Gitlab {
    private List<Card> cards = new ArrayList<>();
    private List<ActionListener> listeners = new ArrayList<>();

    public void registerActionListener(ActionListener listener) {
        listeners.add(listener);
    }

    public static void main(String[] args) {
        /*

            Assignment
                ZippedFile inherited from File


                Quantum/Zipped/Uncompressed
                        Decorator()
                    
                Quantum Satellite, fully downloaded/uploaded onto a QuantumSatellite
                    -> GetFileState(): return new QuantumState(file)
                
                QuantumState(inner)
                    -> GetDataSize(): ("quantum" in inner.GetData() ? 2/3.0 : 1) * inner.GetDataSize()
                    -> GetData(): inner.GetData()

                NormalState
                    -> GetDataSize(): data.length
                    -> GetData(): data

                QuantumState
                    -> GetDataSize(): ("quantum" in data ? 2/3.0 : 1) * data.length
                    -> GetData(): data

                ZippedState
                    Internally caches the zipped as `zipData`
                    -> GetDataSize(): zipData.length
                    -> GetData(): zipData
                
                UnzippedState
                    -> GetDataSize(): data
                    -> GetData(): data.length

                File
                    ContentProvider(raw, totalBytes) -> 


         */

        Gitlab gitlab = new Gitlab();
        gitlab.registerActionListener(new ActionListener() {
            @Override
            public void onCardMoved(Card card, State previousState) {
                System.out.println("Moved to new state");
            }

            @Override
            public void onValidationFailed(Card card, Validation validation) {
                System.err.println(validation.errorMessage());
            }

            @Override
            public Validation externalValidation(Card card) {
                return Validation.Err("BOOOO");
            }
        });
    }
}
